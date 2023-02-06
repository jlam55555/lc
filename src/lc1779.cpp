class Solution {
public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    int res{-1}, best_dist{INT_MAX};
    for (int i{}; i < points.size(); ++i) {
      auto x1{points[i][0]}, y1{points[i][1]};
      if (auto dist{abs(x - x1) + abs(y - y1)};
          (x == x1 || y == y1) && dist < best_dist) {
        best_dist = dist;
        res = i;
      }
    }
    return res;
  }
};
