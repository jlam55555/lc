class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   const vector<int> &click) {
    int m(board.size()), n(board[0].size());
    auto x{click[0]}, y{click[1]};
    if (board[x][y] == 'M') {
      board[x][y] = 'X';
      return board;
    }

    // Reveal mines recursively.
    std::stack<std::pair<int, int>> to_reveal;
    to_reveal.push({x, y});
    while (!to_reveal.empty()) {
      auto [x, y]{to_reveal.top()};
      to_reveal.pop();

      if (board[x][y] != 'E') {
        continue;
      }

      int count{};
#define in_bounds(i, j) ((i) >= 0 && (i) < m && (j) >= 0 && (j) < n)
#define add_count(i, j) count += in_bounds(i, j) && board[i][j] == 'M';
#define add_cell(i, j)                                                         \
  if (in_bounds(i, j))                                                         \
    to_reveal.push({(i), (j)});
      add_count(x - 1, y - 1);
      add_count(x - 1, y);
      add_count(x - 1, y + 1);
      add_count(x, y + 1);
      add_count(x + 1, y + 1);
      add_count(x + 1, y);
      add_count(x + 1, y - 1);
      add_count(x, y - 1);
      if (!count) {
        add_cell(x - 1, y - 1);
        add_cell(x - 1, y);
        add_cell(x - 1, y + 1);
        add_cell(x, y + 1);
        add_cell(x + 1, y + 1);
        add_cell(x + 1, y);
        add_cell(x + 1, y - 1);
        add_cell(x, y - 1);
      }
#undef in_bounds
#undef add_cell
#undef add_count

      board[x][y] = count ? count + '0' : 'B';
    }
    return board;
  }
};
