class Solution {
public:
  vector<int> countBits(int n) {
    std::vector<int> res(n + 1);
    res[0] = 0;
    for (auto i{1}; i <= n; ++i) {
      res[i] = res[i >> 1] + (i & 1);
    }
    return res;
  }
};
