class Solution {
public:
  int rangeBitwiseAnd(unsigned left, unsigned right) {
    int res{};
    for (unsigned bit{1u}; bit; bit <<= 1) {
      // Check if right is in the same region as left.
      res |=
          bit * ((left & bit) && ((right & ~(bit - 1)) == (left & ~(bit - 1))));
    }
    return res;
  }
};
// Each bit flips with period 1<<i
