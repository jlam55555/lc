class Solution {
  using VI = std::vector<int>;
  using UMII = std::unordered_map<int, int>;

public:
  // Compute all possible sums of n1 and n2.
  UMII TwoSum(VI &n1, VI &n2) {
    UMII res;
    for (auto i : n1) {
      for (auto j : n2) {
        ++res[i + j];
      }
    }
    return res;
  }

  int fourSumCount(VI &n1, VI &n2, VI &n3, VI &n4) {
    auto two_sum{TwoSum(n1, n2)};
    int res{};
    for (auto i : n3) {
      for (auto j : n4) {
        res += two_sum[-i - j];
      }
    }
    return res;
  }
};
