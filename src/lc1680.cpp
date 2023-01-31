class Solution {
public:
  int intlen(int n) { return 1 + floor(log2(n)); }

  int concatenatedBinary(int n) {

    unsigned long long res = 0;
    unsigned long long max = (unsigned long long)(1e9 + 7);
    for (int i = 1; i <= n; ++i) {
      int currLen = intlen(i);
      res <<= currLen;
      res |= i;
      res %= max;
    }

    return res;
  }
};
