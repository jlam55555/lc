// Graham scan convex hull. References:
// - The Wikipedia article pseudocode, although that doesn't account
//   for non-vertex points that lie on the convex hull.
// - https://cp-algorithms.com/geometry/convex-hull.html, although I
//   use a different cross-product formula.
class Solution {
  using Point = std::vector<int>;

public:
  // Returns the k coordinate of the cross product of the vectors (p0, p1) and
  // (p1, p2). Returns 0 if p0, p1 are (anti-)parallel. Returns a positive
  // number if anticlockwise. Returns a negative number if clockwise. (Think:
  // right-hand rule). Cross product k = ax*by - ay*bx
  static int CrossProdK(const Point &p0, const Point &p1, const Point &p2) {
    return (p1[0] - p0[0]) * (p2[1] - p1[1]) -
           (p1[1] - p0[1]) * (p2[0] - p1[0]);
  }

  // Used for sorting points by distance relative to p0.
  static int Dist2(const Point &p0, const Point &p1) {
    return (p1[0] - p0[0]) * (p1[0] - p0[0]) +
           (p1[1] - p0[1]) * (p1[1] - p0[1]);
  }

  // Convex hull algorithm.
  std::vector<Point> outerTrees(std::vector<Point> &points) {
    std::vector<Point> stk;

    // Find initial point on the convex hull.
    auto p0{*std::min_element(points.begin(), points.end())};

    // Sort points by polar angle with p0.
    std::sort(points.begin(), points.end(),
              [&p0](const auto &p1, const auto &p2) {
                // Sort by angle from p0 if p0, p1, p2 are not collinear.
                if (auto angle{CrossProdK(p0, p1, p2)}; angle) {
                  return angle > 0;
                }
                // p1 and p2 are collinear with p0.
                // Sort by distance from p0. This is only really needed for
                // points that are collinear with the point P at the beginning
                // and end of the sorted array.
                return Dist2(p0, p1) < Dist2(p0, p2);
              });

    // Reverse order of last points that are collinear to p0. These points lie
    // in the index range [i, n) and should be sorted in decreasing order of
    // distance from p0.
    int n(points.size()), i{n - 1};
    while (i && !CrossProdK(points.front(), points.back(), points[i - 1])) {
      --i;
    };
    std::reverse(points.begin() + i, points.end());

    // Graham scan. Traverse points in a
    // counter-clockwise order (increasing angle).
    for (const auto &p : points) {
      // Pop the last point from the stack if we turn clockwise to reach this
      // point.
      while (stk.size() > 1 &&
             CrossProdK(stk[stk.size() - 2], stk.back(), p) < 0) {
        stk.pop_back();
      }
      stk.push_back(p);
    }

    return stk;
  }
};
