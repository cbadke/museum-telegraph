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

#include <stdio.h>
#include "asserts.h"
#include "../binary_queue.h"

void default_length_is_zero() {
    BinaryQueue* q = bq_create();

    assert_int(0, q->size, __FUNCTION__, __LINE__);
}

void enqueue_increases_size_by_one() {
    BinaryQueue* q = bq_create();

    bq_enqueue(q, HIGH);
    assert_int(1, q->size, __FUNCTION__, __LINE__);
}

void dequeue_decreases_size_by_one() {
    BinaryQueue* q = bq_create();

    bq_enqueue(q, HIGH);
    bq_dequeue(q);
    assert_int(0, q->size, __FUNCTION__, __LINE__);
}

void dequeue_gets_enqueued_value() {
    BinaryQueue* q = bq_create();

    bq_enqueue(q, HIGH);
    bit b = bq_dequeue(q);
    assert_int(HIGH, b, __FUNCTION__, __LINE__);

    bq_enqueue(q, LOW);
    b = bq_dequeue(q);
    assert_int(LOW, b, __FUNCTION__, __LINE__);
}

void can_queue_and_dequeue_multiple_values() {
    BinaryQueue* q = bq_create();

    bq_enqueue(q, HIGH);
    bq_enqueue(q, LOW);
    bq_enqueue(q, LOW);
    bq_enqueue(q, HIGH);
    bq_enqueue(q, LOW);
    assert_int(HIGH, bq_dequeue(q), __FUNCTION__, __LINE__);
    assert_int(LOW, bq_dequeue(q), __FUNCTION__, __LINE__);
    assert_int(LOW, bq_dequeue(q), __FUNCTION__, __LINE__);
    assert_int(HIGH, bq_dequeue(q), __FUNCTION__, __LINE__);
    assert_int(LOW, bq_dequeue(q), __FUNCTION__, __LINE__);
}

int main(int argc, char** argv) {
    printf("Start tests...\n");
    default_length_is_zero();
    enqueue_increases_size_by_one();
    dequeue_decreases_size_by_one();
    dequeue_gets_enqueued_value();
    can_queue_and_dequeue_multiple_values();
    printf("Testing complete\n");
}
