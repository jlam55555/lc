class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int n(grid.size());
    std::vector<std::vector<int>> res(n - 2, std::vector<int>(n - 2));
    for (int i{1}; i < n - 1; ++i) {
      for (int j{1}; j < n - 1; ++j) {
        res[i - 1][j - 1] = std::max({
            grid[i - 1][j - 1],
            grid[i - 1][j],
            grid[i - 1][j + 1],
            grid[i][j - 1],
            grid[i][j],
            grid[i][j + 1],
            grid[i + 1][j - 1],
            grid[i + 1][j],
            grid[i + 1][j + 1],
        });
      }
    }
    return res;
  }
};
