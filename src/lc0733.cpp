class Solution {
public:
  void Dfs(std::vector<std::vector<int>> &b, int c1, int c2, int i, int j,
           int h, int w) {
    if (i < 0 || i >= h || j < 0 || j >= w || b[i][j] != c1) {
      return;
    }

    b[i][j] = c2;
    Dfs(b, c1, c2, i - 1, j, h, w);
    Dfs(b, c1, c2, i + 1, j, h, w);
    Dfs(b, c1, c2, i, j - 1, h, w);
    Dfs(b, c1, c2, i, j + 1, h, w);
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    // Short-circuit.
    if (image[sr][sc] == color) {
      return image;
    }

    auto h{image.size()}, w{image[0].size()};
    Dfs(image, image[sr][sc], color, sr, sc, h, w);
    return image;
  }
};
