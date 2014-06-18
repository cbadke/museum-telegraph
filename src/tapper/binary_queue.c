#include <stdlib.h>

#include "binary_queue.h"

BinaryQueue* bq_create() {
    BinaryQueue* q = (BinaryQueue*)malloc(sizeof(BinaryQueue));
    q->size = 0;
    return q;
}

void bq_enqueue(BinaryQueue* q, bit val) {
    q->size++;
}

void bq_dequeue(BinaryQueue* q) {
    q->size--;
}
