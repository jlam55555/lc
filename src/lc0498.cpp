// Honestly, this looked a little better before clang decided to smush
// it all.
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    std::vector<int> res;
    for (int m(mat.size()), n(mat[0].size()), diags{m + n - 1}, i{}; i < diags;
         ++i) {
      for (int x{(i & 1) ? std::max(0, i - n + 1) : std::min(i, m - 1)},
           y{i - x}, xdiff{(i & 1) ? 1 : -1}, ydiff{-xdiff},
           len{std::min({i + 1, m + n - (i + 1), m, n})}, j{};
           j < len; ++j, x += xdiff, y += ydiff) {
        res.push_back(mat[x][y]);
      }
    }
    return res;
  }
};
