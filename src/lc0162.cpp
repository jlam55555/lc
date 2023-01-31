class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int l = 0, r = nums.size(), m;

    while (l < r) {
      m = (l + r) >> 1;

      // if peak
      if ((!m || nums[m] > nums[m - 1]) &&
          (m == nums.size() - 1 || nums[m] > nums[m + 1])) {
        return m;
      }
      // slope upwards
      if (!m || nums[m] > nums[m - 1]) {
        l = m + 1;
      }
      // slope downwards
      else {
        r = m;
      }
    }

    return l;
  }
};
