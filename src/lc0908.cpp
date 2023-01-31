class Solution {
public:
  int smallestRangeI(vector<int> &nums, int k) {
    // Find the min and max.
    auto mn{INT_MAX}, mx{INT_MIN};
    for (auto i : nums) {
      mn = std::min(mn, i);
      mx = std::max(mx, i);
    }
    return std::max(0, mx - mn - (k << 1));
  }
};
