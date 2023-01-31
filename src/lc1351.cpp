class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    // "Walk" the diagonal
    int r(grid.size()), c(grid[0].size());
    auto res{0}, j{r};
    for (auto i{0}; i < c; ++i) {
      while (j && grid[j - 1][i] < 0) {
        --j;
      }
      res += r - j;
    }
    return res;
  }
};
