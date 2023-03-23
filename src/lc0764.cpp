// Original thought: build the grid out and brute-force it
// by checking the largest size square for each cross.
// O(n^3) time and O(n^2) space solution.
//
// Second thought: build the grid out and do DP: build larger
// crosses based on smaller crosses.
// O(n^3) time and O(n^2) space solution (again).
//
// Third thought: don't build out the grid, instead have a
// better way to find the largest cross for each center. Do
// this by aggregating the mines for each row and column in
// sorted order so we can search them efficiently.
// O(n^2*log(m)) time and O(m) space solution, where m
// is the number of mines (and `m < n^2`).
class Solution {
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    // Build lookup array. O(m) time.
    std::vector<std::vector<int>> rows(n), cols(n);
    for (const auto mine : mines) {
      rows[mine[0]].push_back(mine[1]);
      cols[mine[1]].push_back(mine[0]);
    }

    // Sort rows and columns. O(n*m*log(m)) time.
    for (auto &row : rows) {
      row.push_back(-1);
      row.push_back(n);
      std::sort(row.begin(), row.end());
    }
    for (auto &col : cols) {
      col.push_back(-1);
      col.push_back(n);
      std::sort(col.begin(), col.end());
    }

    // Find largest crosses for each index.
    int res{};
    for (int i{}; i < n; ++i) {
      for (int j{}; j < n; ++j) {
        // Find next and previous mine on this row.
        auto next_col_it{std::lower_bound(rows[i].begin(), rows[i].end(), j)};
        int next_col{*next_col_it}, prev_col{*--next_col_it};

        // Find next and previous mine on this column.
        auto next_row_it{std::lower_bound(cols[j].begin(), cols[j].end(), i)};
        int next_row{*next_row_it}, prev_row{*--next_row_it};

        int cross_size{std::min({
            next_col - j,
            j - prev_col,
            next_row - i,
            i - prev_row,
        })};
        res = std::max(res, cross_size);
      }
    }
    return res;
  }
};
