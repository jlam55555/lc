class Solution {
public:
  // This is a nicely symmetric idiom for the signum function.
  int Sign(int a) { return a < 0 ? -1 : a > 0; }

  // Next iterator helps handle negative values of delta
  // including the case where delta < -n.
  int Next(int i, int delta, int n) { return (i + (delta % n) + n) % n; }

  // Try to traverse a path with the same sign (color).
  bool IsCycle(std::vector<int> &nums, int i) {
    int n(nums.size()), slow{i}, fast{i}, fast_, original_sign{Sign(nums[i])};
    do {
      // Advance slow and fast pointers.
      slow = Next(slow, nums[slow], n);
      fast_ = Next(fast, nums[fast], n);
      fast = Next(fast_, nums[fast_], n);

      // Check that:
      // - The color didn't change along the path.
      // - We don't reach a cycle of length 1 or a seen node.
      if (Sign(nums[slow]) != original_sign ||
          Sign(nums[fast_]) != original_sign ||
          Sign(nums[fast]) != original_sign || fast == fast_) {
        return false;
      }
    } while (slow != fast);

    // If slow and fast pointers meet up, then we have a cycle.
    return true;
  }

  // Mark a path with zeros.
  void Mark(std::vector<int> &nums, int i) {
    int n(nums.size()), original_sign{Sign(nums[i])};
    while (nums[i] && Sign(nums[i]) == original_sign) {
      auto tmp{nums[i]};
      nums[i] = 0;
      i = Next(i, tmp, n);
    }
  }

  // Floyd's cycle finding algorithm. This completes
  // in O(k) time and O(1) space for a cyclic or non-cyclic
  // linked list of length k.
  //
  // We'll mark each cycle we see to avoid traversing it
  // more than a constant number of times (twice). Thus this
  // has an overall time complexity of O(n).
  bool circularArrayLoop(vector<int> &nums) {
    int n(nums.size());

    for (int i{}; i < n; ++i) {
      if (IsCycle(nums, i)) {
        return true;
      }

      Mark(nums, i);
    }

    return false;
  }
};
