class Solution {
public:
  bool hasAlternatingBits(int n) {
    auto b{n & 1};
    while (n) {
      if (b ^ (n & 1)) {
        return false;
      }
      b ^= 1;
      n >>= 1;
    }
    return true;
  }
};
