#define isZero(i, j) (i >= 0 && i < d1 && j >= 0 && j < d2 && !grid[i][j])
#define checkSquare(i, j)                                                      \
  if (isZero(i, j)) {                                                          \
    grid[i][j] = dst + 1;                                                      \
    q.push({i, j});                                                            \
  }

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int d1 = grid.size(), d2 = grid[0].size();

    if (grid[0][0]) {
      return -1;
    }

    // standard bfs
    queue<pair<int, int>> q{};
    grid[0][0] = 2;
    q.push({0, 0});

    while (!q.empty()) {
      auto sq = q.front();
      q.pop();

      auto i = sq.first, j = sq.second;
      auto dst = grid[i][j];

      // already found or not a valid path
      if (dst == 1) {
        continue;
      }

      // reached the end
      if (i == d1 - 1 && j == d2 - 1) {
        return dst - 1;
      }

      checkSquare(i - 1, j - 1);
      checkSquare(i - 1, j);
      checkSquare(i - 1, j + 1);
      checkSquare(i, j - 1);
      checkSquare(i, j + 1);
      checkSquare(i + 1, j - 1);
      checkSquare(i + 1, j);
      checkSquare(i + 1, j + 1);

      // mark this square discovered
      grid[i][j] = 1;
    }

    // no path found
    return -1;
  }
};
