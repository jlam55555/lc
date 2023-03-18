// This is a variation on lc1755.cpp, with the additional
// constraint that the subsequence has to be of a fixed
// length.
class Solution {
public:
  // We use std::vector here rather than std::unordered_set because it is
  // faster empirically.
  void SubsetSums(const std::vector<int> &nums,
                  std::vector<std::vector<int>> &res, int l, int r, int i,
                  int count, int sum) {
    if (l + i == r) {
      res[count].push_back(sum);
      return;
    }
    SubsetSums(nums, res, l, r, i + 1, count, sum);
    SubsetSums(nums, res, l, r, i + 1, count + 1, sum + nums[l + i]);
  }

  int minimumDifference(vector<int> &nums) {
    int n(nums.size() / 2), res{INT_MAX};
    std::vector<std::vector<int>> left(n + 1), right(n + 1);
    SubsetSums(nums, left, 0, n, 0, 0, 0);
    SubsetSums(nums, right, n, 2 * n, 0, 0, 0);

    // Take `split` elements from left, `n-split` from right.
    // This part is basically copied from lc1755.cpp.
    auto total{std::accumulate(nums.begin(), nums.end(), 0)};
    for (int split{}; split <= n; ++split) {
      auto &right_{right[n - split]};
      std::sort(right_.begin(), right_.end());
      for (auto i : left[split]) {
        // Find smallest element of right_ >= target-left[i]
        auto it{
            std::lower_bound(right_.begin(), right_.end(), (total / 2) - i)};
        if (it != right_.end()) {
          res = std::min(res, std::abs(2 * (i + *it) - total));
        }
        if (it != right_.begin()) {
          res = std::min(res, std::abs(2 * (i + *--it) - total));
        }
      }
    }
    return res;
  }
};
