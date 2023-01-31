typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
  // merge row into dp
  void mergeRows(vi &dp, vi &row) {
    for (int i = 0; i < dp.size(); ++i) {
      int minPath = dp[i];
      if (i)
        minPath = min(minPath, dp[i - 1]);
      if (i < dp.size() - 1)
        minPath = min(minPath, dp[i + 1]);
      row[i] += minPath;
    }
    swap(dp, row);
  }

  int minFallingPathSum(vvi &matrix) {
    vi dp = matrix[0];

    for (int i = 1; i < matrix.size(); ++i) {
      mergeRows(dp, matrix[i]);
    }

    int minPathSum = INT_MAX;
    for (auto e : dp) {
      minPathSum = min(minPathSum, e);
    }

    return minPathSum;
  }
};
