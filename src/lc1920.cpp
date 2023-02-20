class Solution {
public:
  // Two passes, no extra space. Use permutation cycles
  // and mark numbers as visited by setting them negative.
  vector<int> buildArray(vector<int> &nums) {
    for (int i{}, n(nums.size()); i < n; ++i) {
      if (nums[i] < 0) {
        // Already visited.
        continue;
      }

      // Do a permutation cycle.
      int j{i}, original{nums[i]};
      while (nums[j] != i) {
        auto next{nums[j]};
        nums[j] = ~nums[next];
        j = next;
      }
      nums[j] = ~original;
    }

    // Invert numbers again.
    for (auto &i : nums) {
      i = ~i;
    }

    return nums;
  }
};
