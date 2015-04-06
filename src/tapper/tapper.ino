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

#include "config.h"
#include "messages.h"
#include "mappings.h"

#define OUT_PIN 13
#define MINUTE 60000
unsigned long startNextMessage = 0;

bool messageTimerElapsed();
void resetMessageTimer();

unsigned long nextInterval();
char* nextMessage();
void tapMessage(char* message, int led);
void tapCharacter(int character, int led);

void setup() {
  resetMessageTimer();

  pinMode(OUT_PIN, OUTPUT);
}

void loop() {

  if(messageTimerElapsed()) {
    char* message = nextMessage();
    tapMessage(message, OUT_PIN);
    free(message);

    resetMessageTimer();
  }
}

bool messageTimerElapsed() {
  unsigned long currentTime = millis();
  return startNextMessage < currentTime;
}

void resetMessageTimer() {
  unsigned long currentTime = millis();
  startNextMessage = currentTime + nextInterval();

  //if overflow, recalculate next startTime
  //currentTime will wrap every ~50 days.
  if(startNextMessage < currentTime) {
    startNextMessage = nextInterval();
  }
}

unsigned long nextInterval() {
  return (unsigned long)random(5*MINUTE, 10*MINUTE);
}

char* nextMessage() {
  int index = (int)random(0, MESSAGES_COUNT);
  return getMessage(index);
}

void tapMessage(char* message, int led) {
  int messIdx = 0;
  int mapIdx = 0;

  for(messIdx = 0; message[messIdx] != '\0'; ++messIdx) {
    char currChar = message[messIdx];
    if(currChar == ' ') {
      delay(INTER_WORD_BREAK);
    }
    else {
      for(mapIdx = 0; mapIdx < MAPPER_LENGTH; ++mapIdx) {
        if(currChar == morseMappings[mapIdx].from) {
          tapCharacter(morseMappings[mapIdx].to, led);
          break;
        }
      }
      delay(INTER_LETTER_BREAK);
    }
  }
}

void tapCharacter(int character, int led) {
  while(character != 0) {
    int bit = character & 0b1;
    character >>= 1;

    digitalWrite(OUT_PIN, bit);
    delay(DOT_LENGTH);
  }

  digitalWrite(OUT_PIN, LOW);
  return;
}
