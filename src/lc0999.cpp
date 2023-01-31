class Solution {
public:
  int numRookCaptures(vector<vector<char>> &board) {
    auto h{board.size()}, w{board[0].size()};

    // Find rook.
    int ri, rj;
    for (auto i{0}; i < h; ++i) {
      for (auto j{0}; j < w; ++j) {
        if (board[i][j] == 'R') {
          ri = i;
          rj = j;
        }
      }
    }

    auto caps{0};
    // Up
    for (auto i{ri - 1}; i >= 0; --i) {
      if (auto p{board[i][rj]}; p != '.') {
        caps += p == 'p';
        break;
      }
    }
    // Down
    for (auto i{ri + 1}; i < h; ++i) {
      if (auto p{board[i][rj]}; p != '.') {
        caps += p == 'p';
        break;
      }
    }
    // Left
    for (auto j{rj - 1}; j >= 0; --j) {
      if (auto p{board[ri][j]}; p != '.') {
        caps += p == 'p';
        break;
      }
    }
    // Right
    for (auto j{rj + 1}; j < w; ++j) {
      if (auto p{board[ri][j]}; p != '.') {
        caps += p == 'p';
        break;
      }
    }

    return caps;
  }
};
