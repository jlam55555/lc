class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    // only have to keep track of the previous two elements
    int a, b, c, i, len = cost.size();

    for (int i = 2, a = b = c = 0; i <= len; ++i) {
      c = min(a + cost[i - 2], b + cost[i - 1]);
      a = b;
      b = c;
    }

    return c;
  }
};
