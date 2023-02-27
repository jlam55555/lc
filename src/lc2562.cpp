class Solution {
public:
  long long findTheArrayConcVal(vector<int> &nums, int l, int r) {
    if (l == r) {
      return 0;
    }
    if (r - l == 1) {
      return nums[l];
    }

    return std::stoll(std::to_string(nums[l]) + std::to_string(nums[r - 1])) +
           findTheArrayConcVal(nums, l + 1, r - 1);
  }

  long long findTheArrayConcVal(vector<int> &nums) {
    return findTheArrayConcVal(nums, 0, nums.size());
  }
};
