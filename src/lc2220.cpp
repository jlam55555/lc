class Solution {
public:
  int minBitFlips(int start, int goal) {
    int diff(start ^ goal), res{};
    while (diff) {
      ++res;
      diff &= diff - 1;
    }
    return res;
  }
};
