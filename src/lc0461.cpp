class Solution {
public:
  int hammingDistance(int x, int y) {
    int n = x ^ y, res = 0;

    // find set bits in n
    while (n) {
      n &= n - 1;
      ++res;
    }

    return res;
  }
};
