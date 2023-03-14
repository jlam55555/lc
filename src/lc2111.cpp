// See also lc0300.cpp for a simple example of patience sort.
// Note that this finds the longest non-strictly increasing
// subsequence by using `std::upper_bound`, while lc0300.cpp uses
// `std::lower_bound` to find the longest strictly-increasing
// subsequence. (This is because we consider repeated elements
// in the non-strict case to be part of the same sequence and
// thus don't merge them.)
class Solution {
public:
  // Returns the longest monotonic (non-strict increasing) subsequence length
  // for the k-group specified by offset i.
  //
  // Also computes and returns the length of the k-group.
  std::pair<int, int> Patience(std::vector<int> &arr, int k, int i) {
    std::vector<int> piles;
    int n(arr.size()), k_grp_len{(n - i - 1) / k + 1};
    for (int j{i}; j < n; j += k) {
      if (auto it{std::upper_bound(piles.begin(), piles.end(), arr[j])};
          it != piles.end()) {
        *it = arr[j];
      } else {
        piles.push_back(arr[j]);
      }
    }
    return {piles.size(), k_grp_len};
  }

  // Perform patience sort (non-strictly increasing) for each k-group
  // to get the longest monotonic subsequence for that k-group. The
  // length of the k-group minus the length of the LMS is the number
  // of elements that need to be changed in this k-group.
  int kIncreasing(vector<int> &arr, int k) {
    int res{};
    for (int i{}, n(arr.size()); i < k; ++i) {
      auto [lms_len, k_grp_len]{Patience(arr, k, i)};
      res += k_grp_len - lms_len;
    }
    return res;
  }
};
