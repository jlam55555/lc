class Solution {
public:
  // Using Wikipedia's algorithm.
  vector<int> grayCode(int n) {
    std::vector<int> res(1 << n);
    for (int i{}, m{1}; i < n; ++i, m <<= 1) {
      for (int j{}; j < m; ++j) {
        res[m + j] = res[m - 1 - j] | m;
      }
    }
    return res;
  }
};
