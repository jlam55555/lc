class Solution {
public:
  int thirdMax(vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), std::greater<>());
    auto num_unique{1};
    for (auto i{1}; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) {
        if (++num_unique == 3) {
          return nums[i];
        }
      }
    }
    return nums[0];
  }
};
