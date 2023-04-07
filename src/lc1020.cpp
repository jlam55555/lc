// Almost question as lc1254.cpp (Number of Closed Islands),
// except that the zeros and ones are switched and it wants
// us to count the number of cells on the enclosed islands.
class Solution {
  using Grid = std::vector<std::vector<int>>;
  struct Result {
    // `good` should probably be renamed to `can_reach_edge`.
    bool good;
    int size;
  };

public:
  // Flood fills an island.
  // Returns whether we can reach the edge, along with the size.
  Result Dfs(Grid &grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return {true, 0};
    }
    if (!grid[i][j]) {
      return {false, 0};
    }
    grid[i][j] = 0;

    auto res1{Dfs(grid, i - 1, j, m, n)}, res2{Dfs(grid, i + 1, j, m, n)},
        res3{Dfs(grid, i, j - 1, m, n)}, res4{Dfs(grid, i, j + 1, m, n)};
    auto size{1 + res1.size + res2.size + res3.size + res4.size};
    return {res1.good || res2.good || res3.good || res4.good, size};
  }

  int numEnclaves(Grid &grid) {
    int res{};
    for (int i{}, m(grid.size()), n(grid[0].size()); i < m; ++i) {
      for (int j{}; j < n; ++j) {
        if (grid[i][j]) {
          auto dfs_res{Dfs(grid, i, j, m, n)};
          if (!dfs_res.good) {
            res += dfs_res.size;
          }
        }
      }
    }
    return res;
  }
};
