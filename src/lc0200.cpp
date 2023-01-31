using Grid = std::vector<std::vector<char>>;

class Solution {
public:
  void dfsClearIsland(Grid &grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
      return;
    }
    grid[i][j] = '0';

    dfsClearIsland(grid, i - 1, j, m, n);
    dfsClearIsland(grid, i + 1, j, m, n);
    dfsClearIsland(grid, i, j - 1, m, n);
    dfsClearIsland(grid, i, j + 1, m, n);
  }

  int numIslands(Grid &grid) {
    // Given that m, n > 0.
    int m = grid.size(), n = grid[0].size();

    int res{};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // If an island is found, clear it
        // and increase island count.
        if (grid[i][j] == '1') {
          dfsClearIsland(grid, i, j, m, n);
          ++res;
        }
      }
    }
    return res;
  }
};
