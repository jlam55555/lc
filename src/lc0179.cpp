class Solution {
public:
  string largestNumber(vector<int> &nums) {
    std::vector<std::string> nums_strs;
    for (auto i : nums) {
      nums_strs.push_back(std::to_string(i));
    }

    std::sort(nums_strs.rbegin(), nums_strs.rend(),
              [](const auto &s1, const auto &s2) { return s1 + s2 < s2 + s1; });

    std::string res;
    for (const auto &v : nums_strs) {
      res += v;
    }
    return res[0] == '0' ? "0" : res;
  }
};
