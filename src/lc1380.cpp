class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    int r(matrix.size()), c(matrix[0].size());
    std::vector<int> rmin(r, 0), cmax(c, 0);

    for (auto i{0}; i < r; ++i) {
      for (auto j{0}; j < c; ++j) {
        auto v{matrix[i][j]};
        if (v < matrix[i][rmin[i]]) {
          rmin[i] = j;
        }
        if (v > matrix[cmax[j]][j]) {
          cmax[j] = i;
        }
      }
    }

    std::vector<int> res;
    for (auto i{0}; i < r; ++i) {
      if (cmax[rmin[i]] == i) {
        res.push_back(matrix[i][rmin[i]]);
      }
    }

    return res;
  }
};
