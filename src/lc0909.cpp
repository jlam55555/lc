// BFS to the last square.
class Solution {
public:
  // Helper function to turn coordinates into the linear
  // Boustrophedon index.
  int Encode(int n, int i, int j) {
    return i * n + ((i & 1) ? n - 1 - j : j) + 1;
  }

  // Helper function to generate the coordinate from the
  // Boustrophedon board.
  std::pair<int, int> Decode(int n, int m) {
    m -= 1;
    int i{m / n}, j{m % n};
    if (i & 1) {
      j = n - 1 - j;
    }
    return {i, j};
  }

  // Helper function to generate the coordinate after moving
  // `move` steps on a nxn Boustrophedon board.
  std::pair<int, int> Move(int n, int i, int j, int move) {
    return Decode(n, std::min(n * n, Encode(n, i, j) + move));
  }

  int snakesAndLadders(vector<vector<int>> &board) {
    int n(board.size()), depth{};
    std::vector<std::vector<bool>> seen(n, std::vector<bool>(n));

    std::stack<std::pair<int, int>> curr, next;
    curr.push({0, 0});
    while (!curr.empty()) {
      while (!curr.empty()) {
        auto [i, j]{curr.top()};
        curr.pop();

        // Don't revisit nodes.
        if (seen[i][j]) {
          continue;
        }
        seen[i][j] = true;

        // Reached the end.
        if (Encode(n, i, j) == n * n) {
          return depth;
        }

        // Iterate through neighbors.
        for (int move{1}; move <= 6; ++move) {
          auto [mi, mj]{Move(n, i, j, move)};
          if (board[n - 1 - mi][mj] == -1) {
            next.push({mi, mj});
          } else {
            next.push(Decode(n, board[n - 1 - mi][mj]));
          }
        }
      }
      std::swap(curr, next);
      ++depth;
    }
    return -1;
  }
};
