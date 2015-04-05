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

#include <stdlib.h>
#include <avr/pgmspace.h>
#include "config.h"

#define MAX_MESSAGE_LENGTH 60
const int MESSAGES_COUNT = 3;
const char message_0[] PROGMEM = "SOS";
const char message_1[] PROGMEM = "THIS IS A GREAT DAY!";
const char message_2[] PROGMEM = "THERE WILL BE A 20 MINUTE DELAY ON THE 1300 TO LETHBRIDGE.";
const char* const messages[] PROGMEM = {
  message_0,
  message_1,
  message_2
};

char* getMessage(int index) {
  if (index < 0 || index >= MESSAGES_COUNT) {
    index = 0;
  }

  char* buffer = (char*)malloc(MAX_MESSAGE_LENGTH);
  strcpy_P(buffer, (char*)pgm_read_word(&(messages[index])));
  return buffer;
}
