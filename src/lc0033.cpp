class Solution {
public:
  // finds *a* (i.e., *any*) index of `target` appearing in `nums`,
  // or -1 if not found
  int binary_search(vector<int> &nums, int target) {
    int l, r, m, len = nums.size();

    for (l = 0, r = len; l < r;) {
      m = (l + r) >> 1;

      if (nums[m] == target) {
        return m;
      } else if (nums[m] > target) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    return -1;
  }

  int search(vector<int> &nums, int target) {

    int l, r, m, len = nums.size();

    l = 0;
    r = len;

    // cout << "len: " << len << endl;

    // no rotation, do a regular binary search
    if (nums[0] < nums[len - 1]) {
      return binary_search(nums, target);
    }

    // left part: if we see a number smaller than nums[0], move left
    if (target >= nums[0]) {
      for (l = 0, r = len; l < r;) {
        m = (l + r) >> 1;

        // cout << l << " " << m << " " << r << endl;

        if (nums[m] == target) {
          return m;
        } else if (nums[m] > target || nums[m] < nums[0]) {
          r = m;
        } else {
          l = m + 1;
        }
      }
    }
    // right part: if we see a larger number, move right
    else {
      for (l = 0, r = len; l < r;) {
        m = (l + r) >> 1;

        // cout << l << " " << m << " " << r << endl;

        if (nums[m] == target) {
          return m;
        } else if (nums[m] < target || nums[m] >= nums[0]) {
          l = m + 1;
        } else {
          r = m;
        }
      }
    }

    return (nums[m] == target) ? m : -1;
  }
};
