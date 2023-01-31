class Solution {
public:
  int totalNQueens(int n) {
    std::vector<std::pair<int, int>> queens{};
    return Dfs(0, n, queens);
  }

  int Dfs(int i, int n, std::vector<std::pair<int, int>> &queens) {
    // We reached the end of the board without conflicts.
    if (i == n) {
      return 1;
    }

    auto count{0};
    for (auto j{0}; j < n; ++j) {
      // See if a queen can be placed here.
      if (!CanPlace(i, j, queens)) {
        continue;
      }

      // Recurse.
      queens.emplace_back(i, j);
      count += Dfs(i + 1, n, queens);
      queens.pop_back();
    }

    return count;
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
