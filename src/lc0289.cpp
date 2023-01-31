class Solution {
public:
  inline int GetNeighbors(const std::vector<std::vector<int>> &b, int i, int j,
                          int r, int c) {
    int res{};
    res += i && j && b[i - 1][j - 1] & 1;
    res += i && b[i - 1][j] & 1;
    res += i && j < c - 1 && b[i - 1][j + 1] & 1;
    res += j < c - 1 && b[i][j + 1] & 1;
    res += i < r - 1 && j < c - 1 && b[i + 1][j + 1] & 1;
    res += i < r - 1 && b[i + 1][j] & 1;
    res += i < r - 1 && j && b[i + 1][j - 1] & 1;
    res += j && b[i][j - 1] & 1;
    return res;
  }

  void gameOfLife(vector<vector<int>> &board) {
    int r = board.size(), c = board[0].size();

    // Kind of do it in place -- modify the second bit.
    for (int i{}; i < r; ++i) {
      for (int j{}; j < c; ++j) {
        auto nbs = GetNeighbors(board, i, j, r, c);
        auto live = board[i][j] & 1;
        board[i][j] |= ((live && (nbs == 2 || nbs == 3)) || (!live && nbs == 3))
                       << 1;
      }
    }

    // Fix the second bit.
    for (int i{}; i < r; ++i) {
      for (int j{}; j < c; ++j) {
        board[i][j] >>= 1;
      }
    }
  }
};
