// DFS each island, see if we can reach an edge.
// Solution almost the same as lc0200.cpp (Number of Islands).x
class Solution {
  using Grid = std::vector<std::vector<int>>;

public:
  // Flood fills an island.
  // Returns true if we reach the edge.
  bool Dfs(Grid &grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return true;
    }
    if (grid[i][j]) {
      return false;
    }
    grid[i][j] = 1;

    auto res1{Dfs(grid, i - 1, j, m, n)}, res2{Dfs(grid, i + 1, j, m, n)},
        res3{Dfs(grid, i, j - 1, m, n)}, res4{Dfs(grid, i, j + 1, m, n)};
    return res1 || res2 || res3 || res4;
  }

  int closedIsland(Grid &grid) {
    int res{};
    for (int i{}, m(grid.size()), n(grid[0].size()); i < m; ++i) {
      for (int j{}; j < n; ++j) {
        res += !grid[i][j] && !Dfs(grid, i, j, m, n);
      }
    }
    return res;
  }
};
