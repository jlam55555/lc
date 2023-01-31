// Linearized indexing
#define GRID(grid, i) ((grid)[(i) / c % r][(i) % c])

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    if (!k) {
      return grid;
    }

    int r(grid.size()), c(grid[0].size()), t{r * c};
    std::vector<std::vector<int>> grid2(r, std::vector<int>(c));
    for (auto i{0}; i < t; ++i) {
      GRID(grid2, i + k) = GRID(grid, i);
    }
    return grid2;
  }
};
