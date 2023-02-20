class Solution {
public:
  int minimumCost(vector<int> &cost) {
    std::sort(cost.rbegin(), cost.rend());
    int res{}, n(cost.size());
    for (int i{}; i < n; i += 3) {
      res += cost[i] + (i < n - 1 ? cost[i + 1] : 0);
    }
    return res;
  }
};
