class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    // Find largest three such that i+j > k
    // If k is too large, shift downwards.
    for (auto i{0}; i < nums.size() - 2; ++i) {
      if (nums[i + 2] + nums[i + 1] > nums[i]) {
        return nums[i + 2] + nums[i + 1] + nums[i];
      }
    }
    return 0;
  }
};
