#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "des_internals.h"

int main() {
  uint64_t key = 0b1000000101000001000100000000100000000000100000100000000001000000;
  uint64_t exp = 0b0000000000100001100000100000000000000010000000000000000010000100;

  printf("%ld", permutedChoice1(key));

 // printf("%" PRIu32 "\n", rightOf(e) );

  return 0;
}
