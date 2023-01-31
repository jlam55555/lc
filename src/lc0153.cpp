class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size(), m;

    while (l < r) {
      m = (l + r) >> 1;

      if (nums[m] < nums[0]) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    return nums[l % nums.size()];
  }
};
