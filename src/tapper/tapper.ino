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

extern "C" {
#include "config.h"
#include "binary_queue.h"
#include "mapper.h"
}

BinaryQueue* queue = 0;
const int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  queue = bq_create();

  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  bq_enqueue(queue, HIGH);
  bq_enqueue(queue, LOW);
  Serial.write("\n\0");
}

void loop() {
  if (queue->size > 0) {
      bit x = bq_dequeue(queue);

      if (x == HIGH) {
          Serial.write("1\0");
      } else {
          Serial.write(" \0");
      }
      digitalWrite(led, x);
      delay(DOT_LENGTH);
  }
}
