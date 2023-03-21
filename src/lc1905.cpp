// Idea: DFS through each island in grid2. If each element
// is also a 1 in grid1, then it's a sub-island.
class Solution {
public:
  // DFS through an island in grid2. Returns whether it is a subisland.
  // Marks elements in grid2 as seen.
  bool Dfs(const std::vector<std::vector<int>> &grid1,
           std::vector<std::vector<int>> &grid2, int m, int n, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || !grid2[i][j]) {
      return true;
    }
    grid2[i][j] = 0;
    auto u{Dfs(grid1, grid2, m, n, i - 1, j)},
        r{Dfs(grid1, grid2, m, n, i, j + 1)},
        b{Dfs(grid1, grid2, m, n, i + 1, j)},
        l{Dfs(grid1, grid2, m, n, i, j - 1)};
    return grid1[i][j] && u && r && b && l;
  }

  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int m(grid1.size()), n(grid1[0].size()), res{};
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        res += grid2[i][j] && Dfs(grid1, grid2, m, n, i, j);
      }
    }
    return res;
  }
};
