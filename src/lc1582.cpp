class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    int rows = mat.size(), cols = mat[0].size();

    vector<int> rowCounts(rows, 0), colCounts(cols, 0);

    // get number in each row and column
    for (int i = 0; i < rows; ++i) {
      int count = 0;
      for (int j = 0; j < cols; ++j) {
        count += mat[i][j];
      }
      rowCounts[i] = count;
    }

    // get number in each row and column
    for (int j = 0; j < cols; ++j) {
      int count = 0;
      for (int i = 0; i < rows; ++i) {
        count += mat[i][j];
      }
      colCounts[j] = count;
    }

    int res = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (mat[i][j] && rowCounts[i] == 1 && colCounts[j] == 1) {
          res++;
          // cout << i << " " << j << endl;
        }
      }
    }

    return res;
  }
};
