class Solution {
public:
  bool checkValid(vector<vector<int>> &matrix) {
    int n(matrix.size());
    std::vector<std::bitset<100>> r(n), c(n);
    for (int i{}; i < n; ++i) {
      for (int j{}; j < n; ++j) {
        r[i].set(matrix[i][j] - 1);
        c[j].set(matrix[i][j] - 1);
      }
    }
    for (int i{}; i < n; ++i) {
      if (r[i].count() != n || c[i].count() != n) {
        return false;
      }
    }
    return true;
  }
};
