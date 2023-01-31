class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start,
                              int destination) {
    int totalSum{0}, res{0};
    auto [s, e] = std::make_pair(std::min(start, destination),
                                 std::max(start, destination));
    for (auto i{0}; i < distance.size(); ++i) {
      totalSum += distance[i];
      if (i >= s && i < e) {
        res += distance[i];
      }
    }
    return std::min(res, totalSum - res);
  }
};
