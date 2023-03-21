// Compute lots of prefix sums: one for each row and
// each column.
//
// Then, to check for a magic square of size k:
// - See if all columns are the same.
// - See if all rows are the same.
// - Check diagonals.
class Solution {
public:
  bool IsMagic(std::vector<std::vector<int>> &grid,
               std::vector<std::vector<int>> &row_pre,
               std::vector<std::vector<int>> &col_pre, int m, int n, int i,
               int j, int k) {

    auto sum{row_pre[i][j + k] - row_pre[i][j]};
    int diag1{}, diag2{};

    for (int l{}; l < k; ++l) {
      if (row_pre[i + l][j + k] - row_pre[i + l][j] != sum ||
          col_pre[i + k][j + l] - col_pre[i][j + l] != sum) {
        return false;
      }
      diag1 += grid[i + l][j + l];
      diag2 += grid[i + k - l - 1][j + l];
    }
    return diag1 == sum && diag2 == sum;
  }

  int largestMagicSquare(vector<vector<int>> &grid) {
    int m(grid.size()), n(grid[0].size());

    // Compute prefix sums.
    std::vector<std::vector<int>> row_pre(m, std::vector<int>(n + 1)),
        col_pre(m + 1, std::vector<int>(n));
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        row_pre[i][j + 1] = row_pre[i][j] + grid[i][j];
        col_pre[i + 1][j] = col_pre[i][j] + grid[i][j];
      }
    }

    // Brute force different sizes of k.
    for (int k{std::min(m, n)}; k > 1; --k) {
      for (int i{}; i <= m - k; ++i) {
        for (int j{}; j <= n - k; ++j) {
          if (IsMagic(grid, row_pre, col_pre, m, n, i, j, k)) {
            return k;
          }
        }
      }
    }

    // Didn't find a magic square with k>1, return 1.
    return 1;
  }
};
