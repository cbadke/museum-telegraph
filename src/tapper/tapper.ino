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
#include "mapper.h"

extern "C" {
#include "binary_queue.h"
}

BinaryQueue* queue = 0;
const int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {

  if (queue != 0 && queue->size > 0) {
    bit x = bq_dequeue(queue);
    digitalWrite(led, x);

    delay(DOT_LENGTH);
  } else {
      if (queue != 0) {
          bq_destroy(queue);
          queue = 0;
      }

      queue = mapToDigital("SOS");
      delay(10*DOT_LENGTH);
  }

}
