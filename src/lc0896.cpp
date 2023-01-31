class Solution {
public:
  bool isMonotonic(vector<int> &nums) {
    if (nums.size() == 1) {
      return true;
    }

    // Check monotonic decreasing
    if (nums.back() < nums.front()) {
      for (auto i{1}; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) {
          return false;
        }
      }
    } else {
      for (auto i{1}; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
          return false;
        }
      }
    }
    return true;
  }
};
