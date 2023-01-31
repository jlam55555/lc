class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    auto sum{0};
    for (auto i : nums) {
      sum += i;
    }
    auto cur_sum{0};
    for (auto i{0}; i < nums.size(); ++i) {
      if (cur_sum == sum - nums[i] - cur_sum) {
        return i;
      }
      cur_sum += nums[i];
    }
    return -1;
  }
};
