#include "config.h"
#include "binary_queue.h"
#include "mapper.h"

void setup() {
  Serial.begin(9600);
}

bool t = false;
void loop() {
 if (!t) {
   t = true;
   Serial.write("hello world");
 }
}
