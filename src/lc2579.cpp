// 1 + 4*0 + 4*1 + 4*2 + 4*3 + ... + 4*(n-1)
class Solution {
public:
  long long coloredCells(int n) {
    return 1 + 4 * static_cast<long long>(n - 1) * n / 2;
  }
};
