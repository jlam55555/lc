class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> cumsum(m + 1, vector<int>(n + 1, 0));

    // generate cumulative array
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cumsum[i + 1][j + 1] =
            mat[i][j] + cumsum[i + 1][j] + cumsum[i][j + 1] - cumsum[i][j];
      }
    }

    // calculate matrix block sum
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mat[i][j] = cumsum[min(i + 1 + k, m)][min(j + 1 + k, n)] -
                    cumsum[min(i + 1 + k, m)][max(j - k, 0)] -
                    cumsum[max(i - k, 0)][min(j + 1 + k, n)] +
                    cumsum[max(i - k, 0)][max(j - k, 0)];
      }
    }

    return mat;
  }
};
