// Try to find the best replacement for each element of nums1.
// Use a binary search.
#define MOD 1000000007
class Solution {
public:
  int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
    // Keep nums1 in sorted order.
    std::set<int> nums1_set{nums1.begin(), nums1.end()};
    int res{}, best_correction{};
    for (int i{}, n(nums1.size()); i < n; ++i) {
      int abs_diff{std::abs(nums1[i] - nums2[i])};
      res = (res + abs_diff) % MOD;

      // Try to find a smaller diff.
      int best_diff{INT_MAX};
      auto it{nums1_set.lower_bound(nums2[i])};
      if (it != nums1_set.end()) {
        best_diff = *it - nums2[i];
      }
      if (it-- != nums1_set.begin()) {
        best_diff = std::min(best_diff, nums2[i] - *it);
      }
      best_correction = std::max(best_correction, abs_diff - best_diff);
    }

    return (res - best_correction + MOD) % MOD;
  }
};
