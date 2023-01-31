#define V(i, j)                                                                \
  (((i) < 0 || (i) == r || (j) < 0 || (j) == w) ? 0 : (++count, img[i][j]))

class Solution {
public:
  vector<vector<int>> imageSmoother(const std::vector<std::vector<int>> &img) {
    auto r{img.size()}, w{img[0].size()};
    std::vector<std::vector<int>> res(r, std::vector<int>(w));
    for (auto i{0}; i < r; ++i) {
      for (auto j{0}; j < w; ++j) {
        auto count{1};
        auto sum{V(i - 1, j - 1) + V(i - 1, j) + V(i - 1, j + 1) + V(i, j - 1) +
                 img[i][j] + V(i, j + 1) + V(i + 1, j - 1) + V(i + 1, j) +
                 V(i + 1, j + 1)};
        res[i][j] = sum / count;
      }
    }
    return res;
  }
};
