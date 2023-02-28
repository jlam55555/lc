class Solution {
public:
  vector<int> applyOperations(vector<int> &nums) {
    for (int i{}, j{}, n(nums.size()), tmp; i < n; ++i) {
      if (!nums[i]) {
        continue;
      } else if (i < n - 1 && nums[i] == nums[i + 1]) {
        tmp = nums[i] * 2;
        nums[i + 1] = 0;
      } else {
        tmp = nums[i];
      }
      nums[i] = 0;
      nums[j++] = tmp;
    }
    return nums;
  }
};
