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

#define DOT_LENGTH 150 //ms
#define INTER_LETTER_BREAK 1*DOT_LENGTH
#define INTER_WORD_BREAK 2*DOT_LENGTH

extern const int MESSAGES_COUNT;

#ifdef __cplusplus
extern "C" {
#endif

  //you are responsible to free() after
  char* GetMessage(int index);

#ifdef __cplusplus
}
#endif

#endif
