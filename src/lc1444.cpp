// We need a way to quickly determine if a submatrix
// contains at least one apple. We can do this with
// a 2-D prefix array. This should allow us to easily
// check a solution using a backtracking approach.
//
// The simplifying aspect of this is that we only
// retain the right and bottom parts after cutting.
// This makes the memoization easy (we only need to store
// one (i,j) coordinate rather than a (i0,j0) and (i1,j1)
// coordinate pair.)
#define MOD 1000000007
class Solution {

  // Memoization, indexed by [k][i][j]. A value of zero
  // indicates we haven't computed this result yet; otherwise
  // we store the result + 1.
  int dp[10][50][51]{};

public:
  int AppleCount(const std::vector<std::vector<int>> &pre, int i0, int j0,
                 int i1, int j1) {
    return pre[i1][j1] - pre[i0][j1] - pre[i1][j0] + pre[i0][j0];
  }

  int ways(const std::vector<std::vector<int>> &pre, int k, int m, int n, int i,
           int j) {
    // Memoization.
    if (dp[k][i][j]) {
      return dp[k][i][j] - 1;
    }

    // No apples in this region. Bad cut.
    if (AppleCount(pre, i, j, m, n) <= k) {
      return (dp[k][i][j] = 1) - 1;
    }

    // Base case.
    if (!k) {
      return (dp[k][i][j] = 2) - 1;
    }

    // Try all vertical cuts.
    long res{};
    for (auto cut{j + 1}; cut < n; ++cut) {
      if (AppleCount(pre, i, j, m, cut)) {
        res = (res + ways(pre, k - 1, m, n, i, cut)) % MOD;
      }
    }

    // Try all horizontal cuts.
    for (auto cut{i + 1}; cut < m; ++cut) {
      if (AppleCount(pre, i, j, cut, n)) {
        res = (res + ways(pre, k - 1, m, n, cut, j)) % MOD;
      }
    }

    return (dp[k][i][j] = res + 1) - 1;
  }

  int ways(vector<string> &pizza, int k) {
    // Generate prefix array.
    int m(pizza.size()), n(pizza[0].size());
    std::vector<std::vector<int>> pre(m + 1, std::vector<int>(n + 1));
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        pre[i + 1][j + 1] =
            (pizza[i][j] == 'A') + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
      }
    }

    return ways(pre, k - 1, m, n, 0, 0);
  }
};
