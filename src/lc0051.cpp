class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<std::vector<std::string>> res{};
    std::vector<std::pair<int, int>> queens{};

    Dfs(0, n, queens, board, res);

    return res;
  }

  void Dfs(int i, int n, std::vector<std::pair<int, int>> &queens,
           std::vector<std::string> &board,
           std::vector<std::vector<std::string>> &res) {

    // We reached the end of the board without conflicts.
    if (i == n) {
      res.push_back(board);
      return;
    }

    for (auto j{0}; j < n; ++j) {
      // See if a queen can be placed here.
      if (!CanPlace(i, j, queens)) {
        continue;
      }

      // Recurse.
      queens.emplace_back(i, j);
      board[i][j] = 'Q';
      Dfs(i + 1, n, queens, board, res);
      board[i][j] = '.';
      queens.pop_back();
    }
  }

  bool CanPlace(int i, int j, const std::vector<std::pair<int, int>> &queens) {
    for (const auto &q : queens) {
      // Check if same column.
      if (q.second == j) {
        return false;
      }
      // Check if diagonal.
      if (std::abs(i - q.first) == std::abs(j - q.second)) {
        return false;
      }
    }
    return true;
  }
};
