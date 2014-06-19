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

#include "binary_queue.h"

BinaryQueue* bq_create() {
    BinaryQueue* q = (BinaryQueue*)calloc(1, sizeof(BinaryQueue));
    return q;
}

void bq_destroy(BinaryQueue* q) {
    free(q);
}

void bq_enqueue(BinaryQueue* q, bit val) {
    BQValue* v = (BQValue*)malloc(sizeof(BQValue));
    v->value = val;
    v->next = 0;

    if (q->head == 0) {
        q->head = v;
    } else {
        q->tail->next = v;
    }
    q->tail = v;
    q->size++;
}

bit bq_dequeue(BinaryQueue* q) {
    BQValue* v = q->head;
    bit retVal = v->value;

    q->head = q->head->next;
    q->size--;

    free(v);
    return retVal;
}
