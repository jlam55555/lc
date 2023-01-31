class Solution {
public:
  vector<int> distributeCandies(int m, int n) {
    auto curr{0}, i{0};
    std::vector<int> res(n, 0);
    while (m > 0) {
      auto diff{std::min(m, ++curr)};
      m -= diff;
      res[(i++) % n] += diff;
    }
    return res;
  }
};
