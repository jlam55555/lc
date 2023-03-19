class Solution {
public:
  vector<int> evenOddBit(int n) {
    std::vector<int> res(2);
    for (int i{}; n; i ^= 1, n >>= 1) {
      res[i] += n & 1;
    }
    return res;
  }
};
