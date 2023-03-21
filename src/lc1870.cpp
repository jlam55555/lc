// Binary search over the solution.
class Solution {
public:
  bool ArrivesOnTime(std::vector<int> &dist, double hour, int speed) {
    double elapsed{};
    for (int i{}, n(dist.size()); i < n; ++i) {
      auto elapsed_part{double(dist[i]) / speed};
      if (i < n - 1) {
        elapsed_part = std::ceil(elapsed_part);
      }
      elapsed += elapsed_part;
    }
    return elapsed <= hour;
  }

  int minSpeedOnTime(vector<int> &dist, double hour) {
    int n(dist.size());
    if (hour <= dist.size() - 1) {
      return -1;
    }

    int l{1}, r{10000000};
    while (l < r) {
      int m((l + r) >> 1);
      if (!ArrivesOnTime(dist, hour, m)) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l;
  }
};
