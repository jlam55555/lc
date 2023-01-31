class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int> &nums) {
    std::vector<bool> res;
    auto n{0};
    for (auto i : nums) {
      res.push_back(!(n = ((n << 1) | i) % 5));
    }
    return res;
  }
};
