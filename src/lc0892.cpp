class Solution {
public:
  int surfaceArea(vector<vector<int>> &grid) {
    auto h{grid.size()}, w{grid[0].size()};
    auto res{0};
    for (auto i{0}; i < h; ++i) {
      for (auto j{0}; j < w; ++j) {
        auto height{grid[i][j]};
        if (!height) {
          continue;
        }
        res += 2 + 4 * height;
        if (i)
          res -= std::min(height, grid[i - 1][j]);
        if (i < h - 1)
          res -= std::min(height, grid[i + 1][j]);
        if (j)
          res -= std::min(height, grid[i][j - 1]);
        if (j < w - 1)
          res -= std::min(height, grid[i][j + 1]);
      }
    }
    return res;
  }
};
