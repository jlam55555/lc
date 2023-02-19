#define BATTLESHIP 'X'
#define EMPTY '.'

class Solution {
public:
  // This feel like an easier version of lc0200.cpp.
  // As the hint suggests, we can do this in one pass without
  // modifying board -- we can tell if we are at the beginning
  // of a battleship by simply seeing if we are at the top-left
  // of it.
  int countBattleships(std::vector<std::vector<char>> &board) {
    int m(board.size()), n(board[0].size()), res{};
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        res += board[i][j] == BATTLESHIP && (!i || board[i - 1][j] == EMPTY) &&
               (!j || board[i][j - 1] == EMPTY);
      }
    }
    return res;
  }
};
