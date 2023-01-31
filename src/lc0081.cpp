class Solution {
public:
  // The target exists in the first sorted array.
  // Note that it may also exist in the second sorted array
  // if `nums[start] == target`.
  bool existsInFirst(std::vector<int> &nums, int start, int target) {
    return nums[start] <= target;
  }

  // Following the official solution exactly because my mind can't
  // think straight right now.
  bool search(vector<int> &nums, int target) {
    int l{0}, r(nums.size()), m, mid;
    while (l < r) {
      m = (l + r) >> 1;
      mid = nums[m];
      auto midInFirst{existsInFirst(nums, l, mid)},
          targetInFirst{existsInFirst(nums, l, target)};
      if (mid == target) {
        return true;
      } else if (nums[l] == mid) {
        ++l;
      } else if (midInFirst && !targetInFirst) {
        l = m + 1;
      } else if (!midInFirst && targetInFirst) {
        r = m;
      } else if (mid < target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return mid == target;
  }
};
