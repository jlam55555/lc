typedef vector<int> vi;
typedef vector<vi> vvi;

class NumMatrix {
  vvi cumsum{};

public:
  NumMatrix(vvi &matrix)
      : cumsum(matrix.size() + 1, vi(matrix[0].size() + 1, 0)) {
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        cumsum[i + 1][j + 1] =
            matrix[i][j] + cumsum[i + 1][j] + cumsum[i][j + 1] - cumsum[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return cumsum[row2 + 1][col2 + 1] - cumsum[row2 + 1][col1] -
           cumsum[row1][col2 + 1] + cumsum[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
