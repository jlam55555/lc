class Solution {
public:
  // inclusive left and right
  // we want to find i in [l, r]
  // invariant is that nums[i] >= target

  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size(), m;
    while (l < r) {
      m = (l + r) / 2;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    // i == l == r
    return l;
  }
};
