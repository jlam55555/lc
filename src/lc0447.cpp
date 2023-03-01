class Solution {
public:
  int Dist2(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
  }

  // More or less brute force. For each center point,
  // find all distances of the other points from this point.
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int n(points.size()), res{};
    for (int i{}; i < n; ++i) {
      std::unordered_map<int, int> dists;
      for (int j{}; j < n; ++j) {
        ++dists[Dist2(points[i][0], points[i][1], points[j][0], points[j][1])];
      }
      for (auto [unused, freq] : dists) {
        res += freq * (freq - 1);
      }
    }
    return res;
  }
};
