class Solution {
public:
  // Looks like the knapsack problem, but is much simpler (since each
  // box has the same weight). So we just greedily choose the boxes
  // with the highest units per box until they are exhausted.
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    std::sort(
        boxTypes.begin(), boxTypes.end(),
        [](const auto &bt1, const auto &bt2) { return bt1[1] >= bt2[1]; });
    int res{};
    for (const auto &bt : boxTypes) {
      auto num_boxes = std::min(truckSize, bt[0]);
      truckSize -= num_boxes;
      res += num_boxes * bt[1];
    }
    return res;
  }
};
