class Solution {
public:
  bool checkXMatrix(vector<vector<int>> &grid) {
    int n(grid.size());
    for (int i{}; i < n; ++i) {
      for (int j{}; j < n; ++j) {
        // Diagonal.
        if (i == j || i == n - 1 - j) {
          if (!grid[i][j]) {
            return false;
          }
        }
        // Not diagonal.
        else if (grid[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
};
