class Solution {
public:
  vector<int> minSubsequence(vector<int> &nums) {
    auto sum{0};
    std::sort(nums.begin(), nums.end());
    for (auto i : nums) {
      sum += i;
    }
    for (int i(nums.size() - 1), sum2{0}; i >= 0; --i) {
      sum2 += nums[i];
      if (sum2 * 2 > sum) {
        std::vector<int> res(nums.begin() + i, nums.end());
        std::reverse(res.begin(), res.end());
        return res;
      }
    }
    throw std::logic_error{"shouldn't reach here"};
  }
};
