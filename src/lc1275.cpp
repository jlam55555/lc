#define PLAYER_X "A"
#define PLAYER_O "B"
#define DRAW "Draw"
#define PENDING "Pending"
#define WINNER(b) ((b) == 'X' ? PLAYER_X : PLAYER_O)
#define EMPTY(v) (!(v))
#define NONEMPTY(v) (!!(v))

class Solution {
public:
  string tictactoe(vector<vector<int>> &moves) {
    std::array<std::array<char, 3>, 3> b{};

    std::string lastState{PENDING};
    auto m{0};
    for (const auto &move : moves) {
      auto mx{move[0]}, my{move[1]};
      b[mx][my] = (m ^= 1) ? 'X' : 'O';
      // PrintBoard(b);
      if ((lastState = CheckDone(b)) != PENDING) {
        return lastState;
      }
    }

    return lastState;
  }

  void PrintBoard(std::array<std::array<char, 3>, 3> &b) {
    for (auto i{0}; i < 3; ++i) {
      for (auto j{0}; j < 3; ++j) {
        std::cout << (b[i][j] == 0 ? '.' : b[i][j]) << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  string CheckDone(std::array<std::array<char, 3>, 3> &b) {
    // Check diagonals.
    auto m{b[1][1]};
    if (NONEMPTY(m) &&
        ((b[0][0] == m && m == b[2][2]) || (b[2][0] == m && m == b[0][2]))) {
      return WINNER(m);
    }

    // Check rows and columns.
    for (auto i{0}; i < 3; ++i) {
      auto r{true}, c{true};
      for (auto j{1}; j < 3; ++j) {
        r &= b[i][j] == b[i][j - 1];
        c &= b[j][i] == b[j - 1][i];
      }
      if (r && NONEMPTY(b[i][0])) {
        return WINNER(b[i][0]);
      }
      if (c && NONEMPTY(b[0][i])) {
        return WINNER(b[0][i]);
      }
    }

    // Check pending.
    for (int i{0}; i < 3; ++i) {
      for (int j{0}; j < 3; ++j) {
        if (EMPTY(b[i][j])) {
          return PENDING;
        }
      }
    }
    return DRAW;
  }
};
