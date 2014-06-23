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

#ifndef __BINARY_QUEUE_H__
#define __BINARY_QUEUE_H__

#include "bit.h"

typedef struct BQValue {
  bit value;
  struct BQValue* next;
} BQValue;

typedef struct {
  int size;
  BQValue* head;
  BQValue* tail;
} BinaryQueue;

BinaryQueue* bq_create();
void bq_destroy(BinaryQueue* q);

void bq_enqueue(BinaryQueue* q, bit val);
bit bq_dequeue(BinaryQueue* q);

#endif
