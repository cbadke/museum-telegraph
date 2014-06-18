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

int main(int argc, char** argv) {
    printf("Start tests...\n");
    default_length_is_zero();
    enqueue_increases_size_by_one();
    dequeue_decreases_size_by_one();
    printf("Testing complete\n");
}
