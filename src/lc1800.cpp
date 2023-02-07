class Solution {
public:
  // Kadane's algorithm with an extra constraint.
  int maxAscendingSum(vector<int> &nums) {
    int res{}, cur_sum{};
    for (int i{}; i < nums.size(); ++i) {
      if (i && nums[i] <= nums[i - 1]) {
        cur_sum = 0;
      }
      cur_sum += nums[i];
      res = std::max(res, cur_sum);
    }
    return res;
  }
};
