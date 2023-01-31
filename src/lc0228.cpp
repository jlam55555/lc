class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    auto l{0};
    std::vector<std::string> res{};
    // Interval is [l, r)
    while (l < nums.size()) {
      auto r{l + 1};
      while (r < nums.size() && nums[r] == nums[r - 1] + 1) {
        ++r;
      }
      res.push_back(r - l == 1 ? std::to_string(nums[l])
                               : (std::to_string(nums[l]) + "->" +
                                  std::to_string(nums[r - 1])));
      l = r;
    }
    return res;
  }
};
