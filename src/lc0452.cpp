// See also: lc0757.cpp. It's a very similar question but
// requires us to put two darts through each balloon.
class Solution {
public:
  // Greedy solution: sort by balloon interval ends, and
  // shoot arrows there, taking out any overlapping balloons.
  //
  // This greedy solution works because we know that we have
  // to put an arrow into the balloon that ends first, so
  // might as well put it in the end where it must overlap
  // the most other balloons. We can use this logic inductively
  // on the whole array.
  int findMinArrowShots(vector<vector<int>> &points) {
    std::sort(points.begin(), points.end(),
              [](const auto &p1, const auto &p2) { return p1[1] < p2[1]; });

    int res{};
    for (int i{}, n(points.size()); i < n;) {
      // Pop all balloons going overlapping balloon i.
      int arrow{points[i][1]}, j{i + 1};
      while (j < n && points[j][0] <= arrow) {
        ++j;
      }
      i = j;
      ++res;
    }
    return res;
  }
};
