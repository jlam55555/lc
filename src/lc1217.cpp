class Solution {
public:
  int minCostToMoveChips(vector<int> &position) {
    int a[]{0, 0};
    for (auto i : position) {
      ++a[i & 1];
    }
    return std::min(a[0], a[1]);
  }
};
