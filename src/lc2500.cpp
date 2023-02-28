class Solution {
public:
  int deleteGreatestValue(vector<vector<int>> &grid) {
    int m(grid.size()), n(grid[0].size());
    for (int i{}; i < m; ++i) {
      std::sort(grid[i].begin(), grid[i].end());
    }

    int res{};
    for (int j{}; j < n; ++j) {
      int max{};
      for (int i{}; i < m; ++i) {
        max = std::max(max, grid[i][j]);
      }
      res += max;
    }
    return res;
  }
};
