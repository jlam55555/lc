class Solution {
public:
  vector<vector<int>> matrixReshape(const vector<vector<int>> &mat, int r,
                                    int c) {
    auto h{mat.size()}, w{mat[0].size()};
    if (h * w != r * c) {
      return mat;
    }

    std::vector<std::vector<int>> res(r, std::vector<int>(c));
    auto pos{0};
    for (const auto &i : mat) {
      for (const auto &j : i) {
        auto l{pos / c};
        auto m{pos % c};
        res[l][m] = j;
        pos++;
      }
    }
    return res;
  }
};
