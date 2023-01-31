class Solution {
public:
  int dfs(vector<vector<int>> &mat, vector<vector<int>> &len, int prev, int i,
          int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] <= prev) {
      return 0;
    }

    if (len[i][j]) {
      return len[i][j];
    }

    int top = dfs(mat, len, mat[i][j], i - 1, j, m, n),
        right = dfs(mat, len, mat[i][j], i, j + 1, m, n),
        down = dfs(mat, len, mat[i][j], i + 1, j, m, n),
        left = dfs(mat, len, mat[i][j], i, j - 1, m, n);

    return len[i][j] = 1 + max(max(top, right), max(down, left));
  }

  // dfs with dp
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> len(m, vector<int>(n));

    int maxLen = INT_MIN;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        maxLen = max(maxLen, dfs(matrix, len, INT_MIN, i, j, m, n));
        // cout << len[i][j] << " ";
      }
      // cout << endl;
    }

    return maxLen;
  }
};
