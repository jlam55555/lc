class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    auto res{0};
    for (auto i{1}; i < points.size(); ++i) {
      auto x1{points[i - 1][0]}, y1{points[i - 1][1]}, x2{points[i][0]},
          y2{points[i][1]}, dx{std::abs(x1 - x2)}, dy{std::abs(y1 - y2)},
          diag{std::min(dx, dy)};
      res += dx + dy - diag;
    }
    return res;
  }
};
