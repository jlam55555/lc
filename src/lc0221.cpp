class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {

    int m = matrix.size(), n = matrix[0].size(), maxSquare = 0;

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      maxSquare |= (mat[i][0] = matrix[i][0] - '0');
    }
    for (int j = 0; j < n; ++j) {
      maxSquare |= (mat[0][j] = matrix[0][j] - '0');
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == '1') {
          mat[i][j] =
              1 + min(mat[i - 1][j - 1], min(mat[i - 1][j], mat[i][j - 1]));
        }

        maxSquare = max(maxSquare, mat[i][j]);
      }
    }

    return maxSquare * maxSquare;
  }
};
