// Patience sort for longest (strictly) increasing subsequence.
//
// See also: lc1671.cpp (does patience sort in both directions)
// and lc2111.cpp (which finds the longest non-decreasing
// subsequence by using `std::upper_bound()`).
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    std::vector<int> piles;
    for (auto i : nums) {
      if (auto it{std::lower_bound(piles.begin(), piles.end(), i)};
          it != piles.end()) {
        *it = i;
      } else {
        piles.push_back(i);
      }
    }
    return piles.size();
  }
};
