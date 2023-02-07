class Solution {
public:
  int minOperations(vector<int> &nums) {
    int res{};
    for (int i{1}; i < nums.size(); ++i) {
      auto diff = std::max(0, nums[i - 1] - nums[i] + 1);
      nums[i] += diff;
      res += diff;
    }
    return res;
  }
};
