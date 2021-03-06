/*
 * Midichords - Midiboy Note To Chord sketch
 * Copyright (C) 2019  Vilniaus Blokas UAB, https://blokas.io/midiboy
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <usbmidi.h>
#include <Midiboy.h>
#include <midi_serialization.h>
#include <fifo.h>
#include <EEPROM.h>

#define FONT MIDIBOY_FONT_5X7

enum { MAX_NOTES = 5 };

enum { EEPROM_SAVE_START_ADDRESS = 20 };
enum { EEPROM_MAGIC_VALUE = 0x59 }; // Arbitrary number.
enum { EEPROM_MAGIC_ADDRESS = EEPROM_SAVE_START_ADDRESS + 0 };
enum { EEPROM_NOTES_ADDRESS = EEPROM_SAVE_START_ADDRESS + 1 };

enum Arrow
{
	ARROW_UP   = 0,
	ARROW_DOWN = 1,
	ARROW_COUNT
};

static const PROGMEM uint8_t ARROW[ARROW_COUNT][5] = {
	{ 0x02, 0x06, 0x0e, 0x06, 0x02 },
	{ 0x40, 0x60, 0x70, 0x60, 0x40 },
};

enum DecoderId
{
	DECODER_MIDI = 0,
	DECODER_USB  = 1,
	DECODER_COUNT
};

typedef TFifo<midi_event_t, uint8_t, 128> fifo_t;

enum Status
{
	STATUS_INFO     = 0,
	STATUS_SAVED    = 1,
	STATUS_RELOADED = 2,
};

bool g_usbSuspended = false;

fifo_t g_outputQueue;
MidiToUsb g_decoder[DECODER_COUNT];

int8_t g_semitones[MAX_NOTES];
uint16_t g_channelsHadActivity = 0;
uint8_t g_selected = 0;

void loadFromEEPROM()
{
	if (EEPROM.read(EEPROM_MAGIC_ADDRESS) == EEPROM_MAGIC_VALUE)
	{
		for (uint8_t i=0; i<MAX_NOTES; ++i)
		{
			g_semitones[i] = EEPROM.read(EEPROM_NOTES_ADDRESS + i);
			if (g_semitones[i] == -128)
				g_semitones[i] = -127;
		}
	}
	else
	{
		memset(g_semitones, 0, sizeof(g_semitones));
	}
}

void saveToEEPROM()
{
	for (uint8_t i=0; i<MAX_NOTES; ++i)
	{
		EEPROM.update(EEPROM_NOTES_ADDRESS + i, g_semitones[i]);
	}
	EEPROM.update(EEPROM_MAGIC_ADDRESS, EEPROM_MAGIC_VALUE);
}

void printStatus(Status status)
{
	switch (status)
	{
	case STATUS_INFO:
		printSpace(0, 7, 10, false);
		print(10, 7, "A: Save, B: Reload.", 19, 128, false);
		break;
	case STATUS_SAVED:
		printSpace(0, 7, 49, false);
		print(49, 7, "Saved.", 6, 128, false);
		break;
	case STATUS_RELOADED:
		printSpace(0, 7, 40, false);
		print(40, 7, "Reloaded.", 9, 128, false);
		break;
	}
}

void onUsbSuspended(bool suspended)
{
	g_usbSuspended = suspended;
}

void setup()
{
	Midiboy.begin();
	Midiboy.setButtonRepeatMs(50);

	USBMIDI.setSuspendResumeCallback(&onUsbSuspended);

	loadFromEEPROM();

	print(22, 0, "Note To Chord:", 14, 128, false);

	g_decoder[DECODER_MIDI].setCable(DECODER_MIDI);
	g_decoder[DECODER_USB].setCable(DECODER_USB);

	for (uint8_t i=0; i<MAX_NOTES; ++i)
	{
		drawSemitones(i);
	}
	drawArrows(g_selected);

	printStatus(STATUS_INFO);
}

void print(uint8_t x, uint8_t line, const char *text, uint8_t n, uint8_t maxWidth, bool inverted)
{
	Midiboy.setDrawPosition(x, 7-(line&7));
	uint8_t width = min(n*(FONT::WIDTH+1), maxWidth);
	uint8_t spaces = maxWidth - width;
	uint8_t counter = 0;
	const uint8_t *p = NULL;
	while (width-- && n)
	{
		switch (counter)
		{
		case 0:
			p = &FONT::DATA_P[(*text++ - ' ') * FONT::WIDTH];
			break;
		case FONT::WIDTH:
			Midiboy.drawSpace(1, inverted);
			--n;
			counter = 0;
			continue;
		default:
			break;
		}

		Midiboy.drawBitmap_P(p++, 1, inverted);
		++counter;
	}
	if (spaces > 0)
	{
		Midiboy.drawSpace(spaces, inverted);
	}
}

void printArrow(uint8_t x, uint8_t line, Arrow arrow, bool inverted)
{
	Midiboy.setDrawPosition(x, 7-(line&7));
	Midiboy.drawBitmap_P(ARROW[arrow], 5, inverted);
}

void printSpace(uint8_t x, uint8_t line, uint8_t w, bool inverted)
{
	Midiboy.setDrawPosition(x, 7-(line&7));
	Midiboy.drawSpace(w, inverted);
}

void printSemitones(uint8_t x, uint8_t line, int8_t semitones, bool inverted)
{
	char text[4];
	memset(text, ' ', sizeof(text));
	bool negative = semitones < 0;
	if (negative) semitones = -semitones;

	uint8_t n = 3;
	do
	{
		text[n--] = semitones % 10 + '0';
		semitones /= 10;
	}
	while (semitones);

	text[n] = negative ? '-' : '+';

	printSpace(x, line, n*6, false);
	print(x+n*6, line, text+n, 4-n, (4-n)*6, inverted);
}

void clearScreen()
{
	Midiboy.clearScreen();
}

bool midi_is_note_on(const midi_event_t &event)
{
	return (event.m_data[0] & 0xf0) == 0x90 && event.m_data[2] >= 0;
}

bool midi_is_note_off(const midi_event_t &event)
{
	uint8_t status = event.m_data[0] & 0xf0;
	return (status == 0x80) || (status == 0x90 && event.m_data[2] == 0);
}

bool midi_is_all_notes_off(const midi_event_t &event)
{
	return (event.m_data[0] & 0xf0) == 0xb0 && event.m_data[1] >= 123;
}

uint8_t normalizeSemitones(int8_t *dst, const int8_t *src, uint8_t n)
{
	if (n > MAX_NOTES)
		return 0;

	uint8_t result = 0;
	for (uint8_t i=0; i<n; ++i)
	{
		int8_t s = src[i];
		if (s != 0)
		{
			bool isDuplicate = false;
			for (uint8_t j=0; j<result; ++j)
			{
				if (dst[j] == s)
				{
					isDuplicate = true;
					break;
				}
			}

			if (!isDuplicate)
				dst[result++] = s;
		}
	}

	return result;
}

void produceEvents(fifo_t &outputQueue, midi_event_t event, const int8_t *semitones, uint8_t n)
{
	int8_t normalized[MAX_NOTES];
	n = normalizeSemitones(normalized, semitones, n);

	outputQueue.push(event);

	int8_t original = event.m_data[1];
	for (uint8_t i=0; i<n; ++i)
	{
		int16_t transposed = original + normalized[i];
		if (transposed < 0 || transposed > 127)
			continue;

		event.m_data[1] = transposed & 0x7f;
		outputQueue.push(event);
	}
}

void clearAllNotes(fifo_t &outputQueue)
{
	midi_event_t allNotesOff;
	allNotesOff.m_event = 0x0b;
	allNotesOff.m_data[1] = 123;
	allNotesOff.m_data[2] = 0;
	for (uint16_t i=0; i<16; ++i)
	{
		if (g_channelsHadActivity & (1 << i))
		{
			allNotesOff.m_data[0] = 0xb0 | i;
			outputQueue.push(allNotesOff);
		}
	}
	g_channelsHadActivity = 0;
}

void processEvent(fifo_t &outputQueue, const midi_event_t &event)
{
	if (midi_is_note_on(event) || midi_is_note_off(event))
	{
		g_channelsHadActivity |= 1 << (event.m_data[0] & 0x0f);
		produceEvents(outputQueue, event, g_semitones, MAX_NOTES);
	}
	else if (midi_is_all_notes_off(event))
	{
		g_channelsHadActivity &= ~(1 << (event.m_data[0] & 0x0f));
		outputQueue.push(event);
	}
	else
	{
		outputQueue.push(event);
	}
}

void processStream(fifo_t &outputQueue, MidiToUsb &decoder, Stream &stream)
{
	while (outputQueue.hasSpaceFor(MAX_NOTES) && stream.available())
	{
		midi_event_t event;
		if (decoder.process(stream.read(), event))
		{
			processEvent(outputQueue, event);
		}
	}
}

void flushOutput(fifo_t &outputQueue)
{
	UsbToMidi encoder;

	uint8_t msg[3];
	midi_event_t event;
	while (outputQueue.pop(event))
	{
		uint8_t n = UsbToMidi::process(event, msg);
		for (uint8_t i=0; i<n; ++i)
		{
			if (!g_usbSuspended)
				Midiboy.usbMidi().write(msg[i]);
			Midiboy.dinMidi().write(msg[i]);
		}
	}
}

void drawSemitones(uint8_t i)
{
	bool selected = i == g_selected;
	printSemitones(2 + i * 24, 4, g_semitones[i], selected);
}

uint8_t digitCount(int8_t x)
{
	if (x < 10 && x > -10)
		return 1;
	if (x < 100 && x > -100)
		return 2;

	return 3;
}

void drawArrows(uint8_t i)
{
	bool selected = i == g_selected;
	if (selected)
	{
		uint8_t w = (digitCount(g_semitones[i])+1)*6;
		uint8_t x = 2 + (i+1)*24 - w/2 - 3;
		printSpace(2+i*24, 3, x-2-i*24, false);
		printArrow(x, 3, ARROW_UP, false);
		printSpace(x+5, 3, 2+(i+1)*24-x-5, false);

		printSpace(2+i*24, 5, x-2-i*24, false);
		printArrow(x, 5, ARROW_DOWN, false);
		printSpace(x+5, 5, 2+(i+1)*24-x-5, false);
	}
	else
	{
		printSpace(2+i*24, 3, 24, false);
		printSpace(2+i*24, 5, 24, false);
	}
}

unsigned long g_eventAt = 0;

void loop()
{
	Midiboy.think();
	processStream(g_outputQueue, g_decoder[DECODER_USB], Midiboy.usbMidi());
	processStream(g_outputQueue, g_decoder[DECODER_MIDI], Midiboy.dinMidi());

	MidiboyInput::Event event;
	while (Midiboy.readInputEvent(event))
	{
		if (event.m_type == MidiboyInput::EVENT_DOWN)
		{
			switch (event.m_button)
			{
			case MidiboyInput::BUTTON_RIGHT:
				if (g_selected < MAX_NOTES-1)
				{
					++g_selected;
					drawArrows(g_selected-1);
					drawArrows(g_selected);
					drawSemitones(g_selected-1);
					drawSemitones(g_selected);
				}
				break;
			case MidiboyInput::BUTTON_LEFT:
				if (g_selected > 0)
				{
					--g_selected;
					drawArrows(g_selected+1);
					drawArrows(g_selected);
					drawSemitones(g_selected+1);
					drawSemitones(g_selected);
				}
				break;
			case MidiboyInput::BUTTON_UP:
				if (g_semitones[g_selected] < 127)
				{
					++g_semitones[g_selected];
					clearAllNotes(g_outputQueue);
					drawSemitones(g_selected);
					drawArrows(g_selected);
				}
				break;
			case MidiboyInput::BUTTON_DOWN:
				if (g_semitones[g_selected] > -127)
				{
					--g_semitones[g_selected];
					clearAllNotes(g_outputQueue);
					drawSemitones(g_selected);
					drawArrows(g_selected);
				}
				break;
			case MidiboyInput::BUTTON_A:
				saveToEEPROM();
				printStatus(STATUS_SAVED);
				g_eventAt = millis() + 1000;
				break;
			case MidiboyInput::BUTTON_B:
				loadFromEEPROM();
				clearAllNotes(g_outputQueue);
				for (uint8_t i=0; i<MAX_NOTES; ++i)
				{
					drawArrows(i);
					drawSemitones(i);
				}
				printStatus(STATUS_RELOADED);
				g_eventAt = millis() + 1000;
				break;
			}
		}
	}

	if (g_eventAt && millis() >= g_eventAt)
	{
		g_eventAt = 0;
		printStatus(STATUS_INFO);
	}

	flushOutput(g_outputQueue);
}
