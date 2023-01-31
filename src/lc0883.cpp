class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    auto h{grid.size()}, w{grid[0].size()};

    // Get bottom projection.
    auto res{0};
    for (auto i{0}; i < h; ++i) {
      for (auto j{0}; j < w; ++j) {
        res += !!grid[i][j];
      }
    }

    // Get row projection.
    for (auto i{0}; i < h; ++i) {
      auto row_max{0};
      for (auto j{0}; j < w; ++j) {
        row_max = std::max(row_max, grid[i][j]);
      }
      res += row_max;
    }

    // Get col projection.
    for (auto j{0}; j < w; ++j) {
      auto col_max{0};
      for (auto i{0}; i < h; ++i) {
        col_max = std::max(col_max, grid[i][j]);
      }
      res += col_max;
    }

    return res;
  }
};
