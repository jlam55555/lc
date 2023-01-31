class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points2) {
    vector<int> points(points2.size());

    for (int i = 0; i < points2.size(); ++i) {
      points[i] = points2[i][0];
    }

    sort(points.begin(), points.end());

    int maxWidth = 0;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i] - points[i - 1] > maxWidth) {
        maxWidth = points[i] - points[i - 1];
      }
    }

    return maxWidth;
  }
};
