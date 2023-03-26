// Simple brute force.
//
// Iterate over the semicircle.
// (x-x0)^2 + (y-y0)^2 = r^2
//
// If we want to find y given x:
// y = y0 +- sqrt(r^2 - (x-x0)^2)
class Solution {
public:
  int countLatticePoints(vector<vector<int>> &circles) {
    std::unordered_set<int> seen;
    for (const auto &c : circles) {
      auto x{c[0]}, y{c[1]}, r{c[2]};
      for (int i{x - r}, i_max{x + r}; i <= i_max; ++i) {
        auto dist{std::sqrt(r * r - (i - x) * (i - x))};
        for (int j(std::ceil(y - dist)), j_max(std::floor(y + dist));
             j <= j_max; ++j) {
          seen.insert((i << 16) | j);
        }
      }
    }
    return seen.size();
  }
};
