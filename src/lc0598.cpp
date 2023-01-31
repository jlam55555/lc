class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    auto min_y{m}, min_x{n};
    for (const auto &op : ops) {
      min_y = std::min(min_y, op[0]);
      min_x = std::min(min_x, op[1]);
    }
    return min_y * min_x;
  }
};
