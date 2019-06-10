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

#include "font.h"

// Font data based on X11 micro which is available as Public Domain font: https://github.com/olikraus/u8g2/wiki/fntgrpx11#micro
// https://cgit.freedesktop.org/xorg/font/micro-misc/tree/COPYING

#define FONT_Y_OFFSET 1

const PROGMEM unsigned char MICRO_FONT[288] = {
	0x00 << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x1D << FONT_Y_OFFSET, 0x1D << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x18 << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET, 0x18 << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x0A << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x0D << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x0B << FONT_Y_OFFSET,
	0x16 << FONT_Y_OFFSET, 0x0C << FONT_Y_OFFSET, 0x1A << FONT_Y_OFFSET,
	0x06 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET,
	0x00 << FONT_Y_OFFSET, 0x08 << FONT_Y_OFFSET, 0x18 << FONT_Y_OFFSET,
	0x00 << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET,
	0x11 << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x15 << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET,
	0x04 << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET,
	0x01 << FONT_Y_OFFSET, 0x03 << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x04 << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET,
	0x01 << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x01 << FONT_Y_OFFSET, 0x06 << FONT_Y_OFFSET, 0x18 << FONT_Y_OFFSET,
	0x0E << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET,
	0x08 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x13 << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET,
	0x11 << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x1E << FONT_Y_OFFSET, 0x02 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1D << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x12 << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x17 << FONT_Y_OFFSET,
	0x10 << FONT_Y_OFFSET, 0x13 << FONT_Y_OFFSET, 0x1C << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1D << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x1E << FONT_Y_OFFSET,
	0x1B << FONT_Y_OFFSET, 0x1B << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x19 << FONT_Y_OFFSET, 0x1B << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x04 << FONT_Y_OFFSET, 0x0A << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET,
	0x0A << FONT_Y_OFFSET, 0x0A << FONT_Y_OFFSET, 0x0A << FONT_Y_OFFSET,
	0x11 << FONT_Y_OFFSET, 0x0A << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET,
	0x10 << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x1C << FONT_Y_OFFSET,
	0x0E << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x19 << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x14 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x1B << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x14 << FONT_Y_OFFSET, 0x14 << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET, 0x17 << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x11 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET,
	0x03 << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET, 0x1B << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x08 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x10 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x14 << FONT_Y_OFFSET, 0x1C << FONT_Y_OFFSET,
	0x1E << FONT_Y_OFFSET, 0x13 << FONT_Y_OFFSET, 0x1D << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x14 << FONT_Y_OFFSET, 0x1B << FONT_Y_OFFSET,
	0x1D << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x17 << FONT_Y_OFFSET,
	0x10 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x10 << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1E << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET, 0x1E << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x02 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x1B << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET, 0x1B << FONT_Y_OFFSET,
	0x1C << FONT_Y_OFFSET, 0x07 << FONT_Y_OFFSET, 0x1C << FONT_Y_OFFSET,
	0x13 << FONT_Y_OFFSET, 0x15 << FONT_Y_OFFSET, 0x19 << FONT_Y_OFFSET,
	0x00 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET,
	0x18 << FONT_Y_OFFSET, 0x06 << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET,
	0x11 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x08 << FONT_Y_OFFSET, 0x10 << FONT_Y_OFFSET, 0x08 << FONT_Y_OFFSET,
	0x01 << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET,
	0x00 << FONT_Y_OFFSET, 0x18 << FONT_Y_OFFSET, 0x08 << FONT_Y_OFFSET,
	0x0B << FONT_Y_OFFSET, 0x0D << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x0B << FONT_Y_OFFSET, 0x0D << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x14 << FONT_Y_OFFSET, 0x10 << FONT_Y_OFFSET,
	0x0D << FONT_Y_OFFSET, 0x0B << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x08 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x00 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x03 << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x1F << FONT_Y_OFFSET, 0x06 << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET,
	0x10 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x08 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x0A << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET,
	0x0E << FONT_Y_OFFSET, 0x0A << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x08 << FONT_Y_OFFSET, 0x0C << FONT_Y_OFFSET,
	0x0D << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET, 0x0B << FONT_Y_OFFSET,
	0x08 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x0E << FONT_Y_OFFSET, 0x01 << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET,
	0x0F << FONT_Y_OFFSET, 0x02 << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET,
	0x09 << FONT_Y_OFFSET, 0x06 << FONT_Y_OFFSET, 0x09 << FONT_Y_OFFSET,
	0x0D << FONT_Y_OFFSET, 0x03 << FONT_Y_OFFSET, 0x0E << FONT_Y_OFFSET,
	0x0B << FONT_Y_OFFSET, 0x0F << FONT_Y_OFFSET, 0x0D << FONT_Y_OFFSET,
	0x04 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x11 << FONT_Y_OFFSET,
	0x00 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x00 << FONT_Y_OFFSET,
	0x11 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET,
	0x08 << FONT_Y_OFFSET, 0x0C << FONT_Y_OFFSET, 0x04 << FONT_Y_OFFSET,
	0x01 << FONT_Y_OFFSET, 0x1F << FONT_Y_OFFSET, 0x10 << FONT_Y_OFFSET,
};

// Font data based on X11 5x7 font which is available as Public Domain font: https://gitlab.freedesktop.org/xorg/font/misc-misc
// https://gitlab.freedesktop.org/xorg/font/misc-misc/blob/master/COPYING
const PROGMEM unsigned char FONT_5X7[475] = {
	0x00, 0x00, 0x00, 0x00, 0x00, // ' '
	0x00, 0x00, 0x7a, 0x00, 0x00, // '!'
	0x00, 0x70, 0x00, 0x70, 0x00, // '"'
	0x14, 0x3e, 0x14, 0x3e, 0x14, // '#'
	0x10, 0x2a, 0x3e, 0x2a, 0x04, // '$'
	0x64, 0x08, 0x10, 0x26, 0x00, // '%'
	0x14, 0x2a, 0x14, 0x02, 0x00, // '&'
	0x00, 0x00, 0x70, 0x00, 0x00, // '''
	0x00, 0x3c, 0x42, 0x00, 0x00, // '('
	0x00, 0x42, 0x3c, 0x00, 0x00, // ')'
	0x00, 0x2a, 0x1c, 0x2a, 0x00, // '*'
	0x08, 0x08, 0x3e, 0x08, 0x08, // '+'
	0x00, 0x01, 0x06, 0x04, 0x00, // ','
	0x08, 0x08, 0x08, 0x08, 0x00, // '-'
	0x00, 0x06, 0x06, 0x00, 0x00, // '.'
	0x04, 0x08, 0x10, 0x20, 0x00, // '/'
	0x00, 0x3c, 0x42, 0x3c, 0x00, // '0'
	0x00, 0x22, 0x7e, 0x02, 0x00, // '1'
	0x22, 0x46, 0x4a, 0x32, 0x00, // '2'
	0x44, 0x52, 0x52, 0x6c, 0x00, // '3'
	0x18, 0x28, 0x7e, 0x08, 0x00, // '4'
	0x74, 0x52, 0x52, 0x4c, 0x00, // '5'
	0x3c, 0x52, 0x52, 0x0c, 0x00, // '6'
	0x40, 0x46, 0x58, 0x60, 0x00, // '7'
	0x2c, 0x52, 0x52, 0x2c, 0x00, // '8'
	0x30, 0x4a, 0x4a, 0x3c, 0x00, // '9'
	0x00, 0x36, 0x36, 0x00, 0x00, // ':'
	0x01, 0x36, 0x34, 0x00, 0x00, // ';'
	0x00, 0x08, 0x14, 0x22, 0x00, // '<'
	0x14, 0x14, 0x14, 0x14, 0x00, // '='
	0x00, 0x22, 0x14, 0x08, 0x00, // '>'
	0x00, 0x20, 0x4a, 0x30, 0x00, // '?'
	0x3c, 0x42, 0x5a, 0x38, 0x00, // '@'
	0x3e, 0x48, 0x48, 0x3e, 0x00, // 'A'
	0x7e, 0x52, 0x52, 0x2c, 0x00, // 'B'
	0x3c, 0x42, 0x42, 0x24, 0x00, // 'C'
	0x7e, 0x42, 0x42, 0x3c, 0x00, // 'D'
	0x7e, 0x52, 0x52, 0x42, 0x00, // 'E'
	0x7e, 0x50, 0x50, 0x40, 0x00, // 'F'
	0x3c, 0x42, 0x4a, 0x2e, 0x00, // 'G'
	0x7e, 0x10, 0x10, 0x7e, 0x00, // 'H'
	0x00, 0x42, 0x7e, 0x42, 0x00, // 'I'
	0x04, 0x02, 0x02, 0x7c, 0x00, // 'J'
	0x7e, 0x18, 0x24, 0x42, 0x00, // 'K'
	0x7e, 0x02, 0x02, 0x02, 0x00, // 'L'
	0x7e, 0x30, 0x30, 0x7e, 0x00, // 'M'
	0x7e, 0x30, 0x0c, 0x7e, 0x00, // 'N'
	0x3c, 0x42, 0x42, 0x3c, 0x00, // 'O'
	0x7e, 0x48, 0x48, 0x30, 0x00, // 'P'
	0x3c, 0x46, 0x42, 0x3d, 0x00, // 'Q'
	0x7e, 0x48, 0x4c, 0x32, 0x00, // 'R'
	0x24, 0x52, 0x4a, 0x24, 0x00, // 'S'
	0x00, 0x40, 0x7e, 0x40, 0x00, // 'T'
	0x7c, 0x02, 0x02, 0x7c, 0x00, // 'U'
	0x78, 0x06, 0x06, 0x78, 0x00, // 'V'
	0x7e, 0x0c, 0x0c, 0x7e, 0x00, // 'W'
	0x66, 0x18, 0x18, 0x66, 0x00, // 'X'
	0x00, 0x70, 0x0e, 0x70, 0x00, // 'Y'
	0x46, 0x4a, 0x52, 0x62, 0x00, // 'Z'
	0x00, 0x7e, 0x42, 0x42, 0x00, // '['
	0x20, 0x10, 0x08, 0x04, 0x00, // '\'
	0x00, 0x42, 0x42, 0x7e, 0x00, // ']'
	0x00, 0x20, 0x40, 0x20, 0x00, // '^'
	0x02, 0x02, 0x02, 0x02, 0x00, // '_'
	0x00, 0x40, 0x20, 0x00, 0x00, // '`'
	0x0c, 0x12, 0x14, 0x1e, 0x00, // 'a'
	0x7e, 0x12, 0x12, 0x0c, 0x00, // 'b'
	0x0c, 0x12, 0x12, 0x00, 0x00, // 'c'
	0x0c, 0x12, 0x12, 0x7e, 0x00, // 'd'
	0x0c, 0x16, 0x1a, 0x08, 0x00, // 'e'
	0x08, 0x3e, 0x48, 0x20, 0x00, // 'f'
	0x0a, 0x15, 0x15, 0x19, 0x00, // 'g'
	0x7e, 0x10, 0x10, 0x0e, 0x00, // 'h'
	0x00, 0x12, 0x5e, 0x02, 0x00, // 'i'
	0x00, 0x02, 0x01, 0x5e, 0x00, // 'j'
	0x7e, 0x08, 0x14, 0x02, 0x00, // 'k'
	0x00, 0x42, 0x7e, 0x02, 0x00, // 'l'
	0x1e, 0x08, 0x18, 0x0e, 0x00, // 'm'
	0x1e, 0x10, 0x10, 0x0e, 0x00, // 'n'
	0x0c, 0x12, 0x12, 0x0c, 0x00, // 'o'
	0x1f, 0x12, 0x12, 0x0c, 0x00, // 'p'
	0x0c, 0x12, 0x12, 0x1f, 0x00, // 'q'
	0x1e, 0x10, 0x10, 0x08, 0x00, // 'r'
	0x0a, 0x1a, 0x16, 0x14, 0x00, // 's'
	0x10, 0x7c, 0x12, 0x02, 0x00, // 't'
	0x1c, 0x02, 0x02, 0x1e, 0x00, // 'u'
	0x00, 0x1c, 0x02, 0x1c, 0x00, // 'v'
	0x1e, 0x06, 0x06, 0x1e, 0x00, // 'w'
	0x12, 0x0c, 0x0c, 0x12, 0x00, // 'x'
	0x18, 0x05, 0x02, 0x1c, 0x00, // 'y'
	0x12, 0x16, 0x1a, 0x12, 0x00, // 'z'
	0x00, 0x10, 0x3c, 0x42, 0x00, // '{'
	0x00, 0x00, 0x7e, 0x00, 0x00, // '|'
	0x00, 0x42, 0x3c, 0x10, 0x00, // '}'
	0x20, 0x40, 0x20, 0x40, 0x00, // '~'
};
