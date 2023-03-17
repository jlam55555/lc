// Standard 2-D DP problem.
//
// We can have a DP array, dp_[i][j] which stores
// the minimum number of characters to transform
// word1[:i] into word2[:j].
//
// The recurrence relation can be described (qualitatively):
// - If character i and j are the same, we don't have
//   to do anything.
//   dp_[i][j] = dp[i-1][j-1]
// - If not the same, we can add the latest character j from word2.
//   dp_[i][j] = dp[i][j-1] + 1
// - We can also try removing the letter from word1.
//   dp_[i][j] = dp[i-1][j] + 1
// - We can also try replacing the letter.
//   dp_[i][j] = dp[i-1][j-1] + 1
//
// By taking the min of these three, we can find the
// minimum number of steps to make the requested change.
//
// My solution as written is almost exactly the same as the
// bottom-up DP solution in the editorial, except that we
// can optimize the solution to use only two rows, like other
// DP recurrences that only depend no the previous row.
// To do this, the `turn` variable keeps track of the current
// row; see lc0494.cpp for a similar solution.
//
// An alternative solution can be a two-sided
// BFS, but this would probably be much less efficient.
class Solution {
  int dp_[2][501]{};

public:
  int minDistance(string word1, string word2) {
    int m(word1.size()), n(word2.size()), turn{};

    // Set up initial row. This row dp_[0][j] represents
    // how many moves it would take to get from the empty
    // string word1[:0] to the string word2[:j].
    for (int j{}; j <= n; ++j) {
      dp_[turn][j] = j;
    }

    for (int i{1}; i <= m; ++i, turn ^= 1) {
      // Set up initial column. This is similar to the
      // initial row above, but transposed.
      dp_[turn ^ 1][0] = i;

      // Fill in the dp matrix. See recurrence relation above.
      for (int j{1}; j <= n; ++j) {
        dp_[turn ^ 1][j] = word1[i - 1] == word2[j - 1]
                               ? dp_[turn][j - 1]
                               : (std::min({dp_[turn][j], dp_[turn ^ 1][j - 1],
                                            dp_[turn][j - 1]}) +
                                  1);
      }
    }

    return dp_[turn][n];
  }
};
