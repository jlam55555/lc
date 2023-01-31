class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    auto h{matrix.size()}, w{matrix[0].size()};
    for (auto i{1}; i < h; ++i) {
      for (auto j{1}; j < w; ++j) {
        if (matrix[i][j] != matrix[i - 1][j - 1]) {
          return false;
        }
      }
    }
    return true;
  }
};
