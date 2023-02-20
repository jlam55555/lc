class Solution {
public:
  int countHillValley(vector<int> &nums) {
    int res{};
    for (int i{}, n(nums.size()); i < n;) {
      int j{i + 1};
      while (j < n && nums[i] == nums[j]) {
        ++j;
      }
      res += i && j < n && nums[i] > nums[i - 1] == nums[j - 1] > nums[j];
      i = j;
    }
    return res;
  }
};
