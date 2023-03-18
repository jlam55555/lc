// "Meet in the middle" approach, similar to lc2035.cpp.
// This approach uses the same intuition as two-way BFS
// to reduce the search space. See @zdu011's solution.
//
// See also: lc2035.cpp
class Solution {
public:
  // Generate all sums.
  void SubsetSums(const std::vector<int> &nums, int l, int r,
                  std::vector<int> &res, int i, int count, int sum) {
    if (l + i == r) {
      res.push_back(sum);
      return;
    }
    SubsetSums(nums, l, r, res, i + 1, count + 1, sum + nums[l + i]);
    SubsetSums(nums, l, r, res, i + 1, count, sum);
  }

  std::vector<int> SubsetSums(const std::vector<int> &nums, int l, int r) {
    std::vector<int> res;
    SubsetSums(nums, l, r, res, 0, 0, 0);
    return res;
  }

  // Improved solution that does better empirically: sort one vector
  // and do a binary search over all its elements.
  int minAbsDifference(vector<int> &nums, int target) {
    // Split data into half, compute all possible sums
    // for each half.
    int n(nums.size());
    auto left_v{SubsetSums(nums, 0, n / 2)},
        right_v{SubsetSums(nums, n / 2, n)};

    // Sort so we can do a binary search.
    std::sort(right_v.begin(), right_v.end());

    // Merge the two halves: this is a a*log(b) pass.
    int res{INT_MAX};
    auto begin_it{right_v.begin()}, end_it{right_v.end()};
    for (auto i : left_v) {
      // Find the first value such that
      // left_v[i] + right_v[j] >= target, or
      // first right_v[j] >= target - left_v[i].
      auto it{std::lower_bound(right_v.begin(), right_v.end(), target - i)};
      if (it != end_it) {
        res = std::min(res, std::abs(i + *it - target));
      }
      if (it != begin_it) {
        res = std::min(res, std::abs(i + *--it - target));
      }

      // Short-circuit.
      if (!res) {
        return res;
      }
    }

    return res;
  }

  // My original solution: sorts both the left and right vectors, and
  // then does a linear pass combining the two. Does worse than the above
  // solution empirically.
  int minAbsDifference_original(vector<int> &nums, int target) {
    // Split data into half, compute all possible sums
    // for each half.
    int n(nums.size());
    auto left_v{SubsetSums(nums, 0, n / 2)},
        right_v{SubsetSums(nums, n / 2, n)};

    // Sort so we can do a linear pass later on.
    std::sort(left_v.begin(), left_v.end());
    std::sort(right_v.rbegin(), right_v.rend());

    // Merge the two halves: find all possible sums from
    // the left and right. This is a linear pass since the array is sorted.
    int res{INT_MAX}, i{}, j{};
    for (int a(left_v.size()), b(right_v.size()); i < a; ++i) {
      while (j + 1 < b && left_v[i] + right_v[j + 1] >= target) {
        ++j;
      }
      // At this point, left_v[i] + right_v[j] >= target,
      // and left_v[i] + right_v[j+1] < target. These two sums
      // are the closest to `target` for this value of `left_v`.
      res = std::min(res, std::abs(left_v[i] + right_v[j] - target));
      if (j + 1 < b) {
        res = std::min(res, std::abs(left_v[i] + right_v[j + 1] - target));
      }

      // Short-circuit.
      if (!res) {
        return res;
      }
    }

    return res;
  }
};
