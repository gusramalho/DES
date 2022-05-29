#include "des.h"

void generateSubkeys(uint64_t key, uint64_t *subkeysBuffer) {
  uint64_t pc1 = permutedChoice1(key);
  uint32_t currentLeft = leftOfPC1(pc1);
  uint32_t currentRight = rightOfPC1(pc1);

  for (int i = 1; i <= 16; i++) {
    uint8_t rotations = subKeyRotationsOf(i);

    currentLeft = rotate28Left(currentLeft, rotations);
    currentRight = rotate28Left(currentRight, rotations);

    subkeysBuffer[i - 1] = permutedChoice2(mergeSubkeys(currentLeft, currentRight));
  }
}

uint64_t des(uint64_t data, uint64_t key, char isEncryption) {
  uint64_t subkeys[16];

  generateSubkeys(key, subkeys);

  uint64_t ipResult = initialPermutation(data);
  
  printf("Initial permutation: %lX to %lX\n", data, ipResult);

  uint32_t leftHalf = leftOf(ipResult);
  uint32_t rightHalf = rightOf(ipResult);

  for (int i = 0; i < 16; i++) {
    uint64_t subkey = isEncryption ? subkeys[i] : subkeys[15 - i];

    printf("Round %i -> Left: %X Right: %X, Subkey: %X\n", i + 1, leftHalf, rightHalf, subkey);
    uint32_t encryptedBlockHalf = feistelFunction(rightHalf, subkey) ^ leftHalf;

    leftHalf = rightHalf;
    rightHalf = encryptedBlockHalf;
  }

  uint64_t merged = mergeBlockHalves(rightHalf, leftHalf);

  uint64_t fpResult = finalPermutation(merged);

  printf("Final permutation: %lX to %lX\n", merged, fpResult);

  return fpResult;
}

uint64_t encrypt(uint64_t plainText, uint64_t key) {
  return des(plainText, key, 1);
}

uint64_t decrypt(uint64_t encrypted, uint64_t key) {
  return des(encrypted, key, 0);
}
