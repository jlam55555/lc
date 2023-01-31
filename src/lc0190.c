uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0, i;

  for (i = 0; i < 16; i++) {
    res |= (n & (0b1u << i)) << (31 - 2 * i);
    res |= (n & (0b1u << 31 - i)) >> (31 - 2 * i);
  }

  return res;
}
