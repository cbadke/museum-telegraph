#include "bit.h"

typedef struct {
    int size;
} BinaryQueue;

BinaryQueue* bq_create();

void bq_enqueue(BinaryQueue* q, bit val);
void bq_dequeue(BinaryQueue* q);
