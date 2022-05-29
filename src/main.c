#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "des.h"

int main() {
  uint64_t key       = 0b0010000001010000010001000000100000000000100000100000000001000000;
  uint64_t plainText = 0b1100100010101010101010101010001010101001011000100000101010001010;

  printf("Plain text: %lX\n", plainText);
  printf("Plain key: %lX\n\n", key);

  uint64_t encrypted = encrypt(plainText, key);
  printf("Encrypted: %lX\n\n", encrypted);

  uint64_t decrypted = decrypt(encrypted, key);
  printf("Decrypted: %lX\n\n", decrypted);

  return 0;
}
