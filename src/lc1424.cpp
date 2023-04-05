// Same as @lee215's solution.
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
    std::vector<std::vector<int>> diags;
    for (int i{}, n(nums.size()); i < n; ++i) {
      for (int j{}, m(nums[i].size()); j < m; ++j) {
        if (diags.size() <= i + j) {
          diags.push_back({});
        }
        diags[i + j].push_back(nums[i][j]);
      }
    }

    // Flatten diagonals.
    std::vector<int> res;
    std::for_each(diags.begin(), diags.end(), [&res](const auto &diag) {
      res.insert(res.end(), diag.rbegin(), diag.rend());
    });
    return res;
  }
};
