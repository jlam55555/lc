class Solution {
public:
  // We want to find the geometric median.
  // In the 1-D case, this is the median.
  // See: https://en.wikipedia.org/wiki/Geometric_median
  //
  // Using quickselect, I solve this in O(n) time.
  int minMoves2(vector<int> &nums) {
    int n(nums.size());
    auto med_it{nums.begin() + n / 2};
    std::nth_element(nums.begin(), med_it, nums.end());

    auto med{*med_it};
    return std::accumulate(nums.begin(), nums.end(), 0,
                           [med](const auto &acc, const auto &val) {
                             return acc + std::abs(val - med);
                           });
  }
};
