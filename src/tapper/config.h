//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <WString.h>

const int DOT_LENGTH = 150; //ms
const int INTER_LETTER_BREAK = 1;
const int INTER_WORD_BREAK = 2;

typedef struct{
  String from;
  String to;
} Mapping;

/*
extern Mapping morseMappings[];
*/

#endif
