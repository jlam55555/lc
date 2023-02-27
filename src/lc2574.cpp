class Solution {
public:
  vector<int> leftRightDifference(vector<int> &nums) {
    // Compute prefix sum.
    int n(nums.size()), total{};
    std::vector<int> prefix(n);
    for (int i{}; i < n - 1; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
      total += nums[i];
    }
    total += nums[n - 1];

    // Compute `answer` (in place).
    for (int i{}; i < n; ++i) {
      auto left_sum{prefix[i]};
      auto right_sum{total - left_sum - nums[i]};
      nums[i] = std::abs(left_sum - right_sum);
    }
    return nums;
  }
};
