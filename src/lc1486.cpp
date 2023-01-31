class Solution {
public:
  int xorOperation(int n, int start) {
    int max, res;
    for (max = start + 2 * n, res = 0; start < max; start += 2) {
      res ^= start;
    }
    return res;
  }
};
