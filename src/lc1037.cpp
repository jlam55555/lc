class Solution {
public:
  bool isBoomerang(vector<vector<int>> &points) {
    auto a{points[0]}, b{points[1]}, c{points[2]};
    auto ax{a[0]}, ay{a[1]}, bx{b[0]}, by{b[1]}, cx{c[0]}, cy{c[1]};

    if (a == b || b == c || a == c) {
      return false;
    }

    // Check that collinear.
    auto dx1{bx - ax}, dy1{by - ay}, dx2{cx - ax}, dy2{cy - ay};

    // Make sure they aren't a multiple of one another.
    if (!dx1 && !dx2 || !dy1 && !dy2 || float(dx1) / dx2 == float(dy1) / dy2) {
      return false;
    }

    return true;
  }
};
