class Solution {
public:
  vector<int> sumZero(int n) {
    std::vector<int> res;
    if (n & 1) {
      res.push_back(0);
    }
    for (auto i{0}; i < (n >> 1); ++i) {
      res.push_back(i + 1);
      res.push_back(-i - 1);
    }
    return res;
  }
};
