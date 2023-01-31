class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &points) {
    auto l{points.size()};
    float largest_area{0};
    for (auto i{0}; i < l; ++i) {
      for (auto j{0}; j < l; ++j) {
        for (auto k{0}; k < l; ++k) {
          if (i == j || j == k || i == k) {
            continue;
          }
          float ax(points[i][0]), ay(points[i][1]), bx(points[j][0]),
              by(points[j][1]), cx(points[k][0]), cy(points[k][1]),
              area{std::abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) /
                   2};
          largest_area = std::max(largest_area, area);
        }
      }
    }
    return largest_area;
  }
};
