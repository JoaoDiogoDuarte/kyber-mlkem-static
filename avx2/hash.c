#include "hash.h"
#include <stddef.h>
#include <stdint.h>
#include "KeccakSpongeWidth1600.h"


int sha3_256(uint8_t *h, const uint8_t *in, size_t inlen) {
  return KeccakWidth1600_Sponge(1088, 512, in, inlen, 0x06, h, 32);
}