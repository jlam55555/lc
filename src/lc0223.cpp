struct Point {
  Point(int x, int y) : x{x}, y{y} {}
  const int x, y;
};

struct Rect {
  Rect(int x1, int y1, int x2, int y2)
      : l{x1}, r{x2}, b{y1}, t{y2}, w{r - l}, h{t - b}, bl{l, b}, br{r, b},
        tl{l, t}, tr{r, t} {}

  int Area() const { return w * h; }

  // If rectangle has either dimension negative, then return 0;
  int AreaPositive() const {
    if (w < 0 || h < 0) {
      return 0;
    }
    return Area();
  }

  Rect Intersect(const Rect &r2) const {
    auto intersect_right{std::min(r, r2.r)};
    auto intersect_left{std::max(l, r2.l)};
    auto intersect_top{std::min(t, r2.t)};
    auto intersect_bottom{std::max(b, r2.b)};
    return Rect{intersect_left, intersect_bottom, intersect_right,
                intersect_top};
  }

  const int l, r, t, b, w, h;
  const Point bl, br, tl, tr;
};

class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    Rect a{ax1, ay1, ax2, ay2};
    Rect b{bx1, by1, bx2, by2};

    // Note that the corners of the overlapping area must
    // be aligned with corners of the rectangles.
    return a.Area() + b.Area() - a.Intersect(b).AreaPositive();
  }
};
