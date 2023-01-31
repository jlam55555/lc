class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    auto h{grid.size()}, w{h ? grid[0].size() : 0};
    auto edges{0};
    for (auto i{0}; i < h; ++i) {
      for (auto j{0}; j < w; ++j) {
        if (grid[i][j]) {
          edges += 4;
          if (i && grid[i - 1][j])
            --edges;
          if (i < h - 1 && grid[i + 1][j])
            --edges;
          if (j && grid[i][j - 1])
            --edges;
          if (j < w - 1 && grid[i][j + 1])
            --edges;
        }
      }
    }
    return edges;
  }
};
