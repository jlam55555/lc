class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0, r = nums.size(), h, left, right;

    if (!r) {
      goto fail;
    }

    // find left
    while (l < r) {
      h = (l + r) / 2;
      // got the right one
      if (nums[h] == target && (!h || nums[h - 1] < target)) {
        break;
      }
      // too large, move left
      else if (nums[h] >= target) {
        r = h;
      }
      // too small, move right
      else {
        l = h + 1;
      }
    }

    // not found
    if (nums[h] != target) {
      goto fail;
    }
    left = h;

    l = 0, r = nums.size();
    while (l < r) {
      h = (l + r) / 2;
      // got the right one
      if (nums[h] == target && (h == nums.size() - 1 || nums[h + 1] > target)) {
        break;
      }
      // too small, move right
      else if (nums[h] <= target) {
        l = h + 1;
      }
      // too large, move left
      else {
        r = h;
      }
    }
    right = h;

    return vector<int>{left, right};

  fail:
    return vector<int>{-1, -1};
  }
};
