class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>> &matrix) {
    auto h{matrix.size()}, w{matrix[0].size()};
    std::vector<std::vector<int>> res(w, std::vector<int>(h));
    for (auto i{0}; i < h; ++i) {
      for (auto j{0}; j < w; ++j) {
        res[j][i] = matrix[i][j];
      }
    }
    return res;
  }
};
