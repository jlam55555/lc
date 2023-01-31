int hammingWeight(uint32_t n) {
  char count = 0;
  do {
    count += n & 0b1u;
  } while (n >>= 1);
  return count;
}
