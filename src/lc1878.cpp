// Brute-force. Like @votrubac says, it seems that the
// difficulty of the question lies in the tediousness of
// getting the rhombi sum correct.
//
// Linear height/width of a rhombus = 2*s+1, where
// s is the side length. Thus, for an mxn grid, we can
// have a rhombus with maximum side length ((min(m, n)-1)/2).
class Solution {
public:
  vector<int> getBiggestThree(vector<vector<int>> &grid) {
    std::vector<int> res(3);
    for (int m(grid.size()), n(grid[0].size()), s{},
         max_s{(std::min(m, n) - 1) / 2};
         s <= max_s; ++s) {
      for (int i{}, len{2 * s + 1}; i + len <= m; ++i) {
        for (int j{}; j + len <= n; ++j) {
          // Special handling for zero-area rhombi.
          int rho_sum{};
          if (!s) {
            rho_sum = grid[i][j];
          } else {
            // Get the sum of the rhombus with side length s
            // whose top left corner is (i, j).
            for (int k{}; k < s; ++k) {
              rho_sum +=
                  grid[i + k][j + s + k] + grid[i + s + k][j + 2 * s - k] +
                  grid[i + 2 * s - k][j + s - k] + grid[i + s - k][j + k];
            }
          }

          // Keep track of top three elements.
          if (rho_sum == res[0] || rho_sum == res[1] || rho_sum == res[2]) {
            continue;
          } else if (rho_sum > res[0]) {
            res[2] = res[1];
            res[1] = res[0];
            res[0] = rho_sum;
          } else if (rho_sum > res[1]) {
            res[2] = res[1];
            res[1] = rho_sum;
          } else if (rho_sum > res[2]) {
            res[2] = rho_sum;
          }
        }
      }
    }

    int distinct{!res[1] ? 1 : !res[2] ? 2 : 3};
    return {res.begin(), res.begin() + distinct};
  }
};
