// For each element nums[i], we want to find out how many
// elements we need to delete on the left and right. On the
// left, we want to find the least elements to delete so
// that we have a increasing subsequence ending at i. In other
// words, we want to find the longest increasing subsequence
// ending at i. And vice versa for the right.
//
// Thus we run the patience sort algorithm for finding the
// longest increasing subsequence from both the left and the
// right. (See lc0300.cpp for LIS implementation.)
//
// Time complexity is O(n*log(n)) (we do two patience sort
// passes and one linear pass) and space complexity is O(n)
// (we store two auxiliary arrays of length n).
class Solution {
public:
  // Performs the longest increasing subsequence algorithm (patience sort)
  // for each element in the input array. Refer to lc0300.cpp for a
  // simple patience sort example.
  //
  // The returned array (call this `arr`) will be such that `arr[i]` is
  // the length of the longest monotonic subsequence ending at (and
  // including) `nums[i]`.
  template <class It> void Patience(It nums_begin, It nums_end, It res_it) {
    std::vector<int> piles;
    for (auto nums_it{nums_begin}; nums_it != nums_end; ++nums_it) {
      auto piles_it{std::lower_bound(piles.begin(), piles.end(), *nums_it)};
      *res_it++ = std::distance(piles.begin(), piles_it) + 1;
      if (piles_it != piles.end()) {
        *piles_it = *nums_it;
      } else {
        piles.push_back(*nums_it);
      }
    }
  }

  int minimumMountainRemovals(vector<int> &nums) {
    int n(nums.size());

    // Perform patience sort in the forward and backward direction.
    std::vector<int> forward(n), backward(n);
    Patience(nums.begin(), nums.end(), forward.begin());
    Patience(nums.rbegin(), nums.rend(), backward.rbegin());

    int res{INT_MAX};
    for (int split{}; split < n; ++split) {
      // Cannot make a mountain out of this split.
      if (forward[split] == 1 || backward[split] == 1) {
        continue;
      }

      // Compute number of elements to remove from
      // left and right.
      auto remove_left{(split + 1) - forward[split]};
      auto remove_right{(n - split) - backward[split]};
      res = std::min(res, remove_left + remove_right);
    }
    return res;
  }
};
