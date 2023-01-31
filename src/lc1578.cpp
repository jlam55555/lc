class Solution {
public:
  int minCost(string s, vector<int> &cost) {

    int left = -1, right = -1, i, len = cost.size(), totalCost = 0;

    for (i = 0; i < len; ++i) {

      // first in a group
      if (!i || s[i] != s[i - 1]) {
        left = i;
      }

      // last in a group
      if (i == len - 1 || s[i] != s[i + 1]) {
        right = i;

        // if length 1, not a repeated letter
        if (left == right) {
          continue;
        }

        // iterate over the group, summing their costs
        // find maximum cost
        int costSum = 0, maxCost = INT_MIN;
        for (int j = left; j <= right; ++j) {
          costSum += cost[j];
          maxCost = max(maxCost, cost[j]);
        }
        costSum -= maxCost;

        totalCost += costSum;
      }
    }

    return totalCost;
  }
};
