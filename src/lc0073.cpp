class Solution {
public:
  void setZeroes(vector<vector<int>> &m) {
    unordered_set<int> rows, cols;
    int dim1 = m.size(), dim2 = m[0].size();

    for (int i = 0; i < dim1; ++i) {
      for (int j = 0; j < dim2; ++j) {
        if (m[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    for (auto row : rows) {
      for (int j = 0; j < dim2; ++j) {
        m[row][j] = 0;
      }
    }

    for (auto col : cols) {
      for (int i = 0; i < dim1; ++i) {
        m[i][col] = 0;
      }
    }
  }
};
