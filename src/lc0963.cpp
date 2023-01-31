class Solution {
public:
  // int dotProd(int p1, int p2, int p3, vector<vector<int>> &points) {
  //     // calculate dot product: x1 * x2 + y1 * y2, make sure it's equal to
  //     zero return (points[p2][0] - points[p1][0]) * (points[p3][0] -
  //     points[p1][0])
  //         + (points[p2][1] - points[p1][1]) * (points[p3][1] -
  //         points[p1][1]);
  // }

  double minAreaFreeRect(vector<vector<int>> &points) {
    int i, j, k, len = points.size(), p1, p2, p3, x1, x2, y1, y2;
    double area, minArea = -1;

    // save all (x, y) pairs (encoded into a single integer) in a hashset for
    // quick searches
    unordered_set<int> ps(0);
    for (i = 0; i < len; ++i)
      ps.insert(points[i][0] * 40000 + points[i][1]);

    // cubic search for rectangles; loop over every triple (i, j, k), where i,
    // j, k are distinct
    for (i = 0; i < len; ++i) {
      for (j = 0; j < len; ++j) {
        if (i == j)
          continue;

        for (k = 0; k < len; ++k) {
          if (i == k || j == k)
            continue;

          // check if JIK or IJK or IKJ is a right angle by calculating the dot
          // product of two vectors and checking if it's zero; if one is a right
          // angle, set the vertex point to be p1; otherwise no valid right
          // angle, continue if (dotProd(p1 = i, p2 = j, p3 = k, points)
          //    && dotProd(p1 = j, p2 = i, p3 = k, points)
          //    && dotProd(p1 = k, p2 = i, p3 = j, points))
          //     continue;

          x1 = points[i][0] - points[k][0];
          x2 = points[j][0] - points[k][0];
          y1 = points[i][1] - points[k][1];
          y2 = points[j][1] - points[k][1];

          if (x1 * x2 + y1 * y2)
            continue;

          // area is sqrt((x1^2 + y1^2) * (x2^2 + y2^2))
          area = sqrt(((unsigned long)x1 * x1 + y1 * y1) * (x2 * x2 + y2 * y2));
          if (minArea != -1 && area >= minArea)
            continue;

          // search for fourth point at (p1.x + x1 + x2, p1.y + y1 + y2)
          // hashset makes this roughly O(1)
          if (ps.count((points[k][0] + x1 + x2) * 40000 +
                       (points[k][1] + y1 + y2)))
            minArea = area;
        }
      }
    }

    return minArea == -1 ? 0 : minArea;
  }
};
