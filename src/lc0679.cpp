// General idea: evaluate all subexpressions for all permutations
// of `cards`. Bottom-up DP solution.
//
// Alternative methods:
// - Backtracking (editorial solution)
// - Enumerate all solutions (e.g., @zestypanda's solution); the
//   search space is small enough to do so.
class Solution {
  std::vector<float> dp[4][5];

public:
  bool judgePoint24(vector<int> &cards, int n = 4, int target = 24) {
    for (int i{}; i < 24 /* == n! */; ++i) {
      // Clear DP array.
      for (int i{}; i < n; ++i) {
        for (int j{i + 1}; j <= n; ++j) {
          dp[i][j].clear();
        }
      }

      // Try solving.
      if (Try24Perm(cards, n, target)) {
        return true;
      }

      // Try next permutation.
      std::next_permutation(cards.begin(), cards.end());
    }
    return false;
  }

  // Brute force a single permutation.
  bool Try24Perm(const std::vector<int> &cards, int n, int target) {
    // Base case: single numbers.
    for (int i{}; i < n; ++i) {
      dp[i][i + 1].push_back(cards[i]);
    }

    // Bottom-up DP. Iterate length of expression.
    for (int k{2}; k <= n; ++k) {
      // Iterate start of expression.
      for (int i{}; i <= n - k; ++i) {
        // Iterate split point.
        for (int split{1}; split < k; ++split) {
          // Try all binary operations.
          auto &res{dp[i][i + k]};
          for (auto a : dp[i][i + split]) {
            for (auto b : dp[i + split][i + k]) {
              res.push_back(a + b);
              res.push_back(a - b);
              res.push_back(a * b);
              if (b) {
                res.push_back(a / b);
              }
            }
          }
        }
      }
    }

    // See if we have a solution.
    for (auto i : dp[0][n]) {
      if (std::abs(i - target) < 1e-3) {
        return true;
      }
    }
    return false;
  }
};
