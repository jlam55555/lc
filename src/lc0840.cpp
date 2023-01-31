#define VAL_RCE(a, b, c)                                                       \
  (a + b + c == 15 && a < 10 && b < 10 && c < 10 && a != b)
#define VAL_RCDC(a, c) (a + c == 10 && a < 10 && c < 10 && a != c)

class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    int count = 0, i, j;

    for (i = 0; i < (int)grid.size() - 2; ++i)
      for (j = 0; j < (int)grid[0].size() - 2; ++j)
        if (grid[i + 1][j + 1] == 5 &&

            VAL_RCE(grid[i][j], grid[i][j + 1], grid[i][j + 2]) &&
            VAL_RCDC(grid[i + 1][j], grid[i + 1][j + 2]) &&
            VAL_RCE(grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]) &&

            VAL_RCE(grid[i][j], grid[i + 1][j], grid[i + 2][j]) &&
            VAL_RCDC(grid[i][j + 1], grid[i + 2][j + 1]) &&
            VAL_RCE(grid[i][j + 2], grid[i + 1][j + 2], grid[i + 2][j + 2]) &&

            VAL_RCDC(grid[i][j], grid[i + 2][j + 2]) &&
            VAL_RCDC(grid[i + 2][j], grid[i][j + 2])) {
          ++count;
          ++j;
        }

    return count;
  }
};
