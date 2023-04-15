// DP problem. We go pile by pile, and keep track of the
// max score for choosing i elements for all the piles
// seen so far, for i in [0, k).
//
// Recurrence relation:
//     dp[pile][i] = max({ sum(pile[0:j]) + dp[pile-1][i-j] })
// for all j < min(i, k). I.e., we choose j elements from the pile,
// and i-j elements from the previous pile(s), and take the maximum
// score of all of these.
//
// Since the solution for one pile depends on the result from
// the previous result only, we can make the usual optimization
// of alternating arrays rather than using a matrix.
//
// This was a fun recurrence relation that I'm happy to have figured
// out on my own without any trouble. It is also a fairly short
// Leetcode hard solution.
class Solution {
public:
  int maxValueOfCoins(vector<vector<int>> &piles, int k) {
    std::vector<int> curr(k + 1), next(k + 1);
    for (const auto &pile : piles) {
      for (int i{1}; i <= k; ++i) {
        for (int j{}, sum{}, n{std::min(i, int(pile.size()))}; j <= n; ++j) {
          next[i] = std::max(next[i], sum + curr[i - j]);
          if (j < n) {
            sum += pile[j];
          }
        }
      }
      std::swap(curr, next);
    }
    return curr[k];
  }
};
