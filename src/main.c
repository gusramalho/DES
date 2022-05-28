#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "des_internals.h"

int main() {
  uint64_t e = 0b1000000000000000000000000000000000000000000000000000000000000000;
  uint64_t x = 0b0000000000000000000000000000000000000001000000000000000000000000;

  printf("%" PRIu32 "\n", rightOf(e) );

  return 0;
}
