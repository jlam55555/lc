// Optimal strategy: sort `nums`, and then pick the smallest
// number (that hasn't been picked yet) that is larger than
// the current number.
class Solution {
public:
  int maximizeGreatness(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int res{};
    for (int i{}, j{}, n(nums.size()); j < n; ++i, ++j) {
      while (j < n && nums[j] <= nums[i]) {
        ++j;
      }
      res += j < n;
    }
    return res;
  }
};
