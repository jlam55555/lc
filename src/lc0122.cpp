class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // reap all the profits
    int profit = 0;

    for (int i = 0; i < prices.size() - 1; ++i) {
      profit += max(prices[i + 1] - prices[i], 0);
    }

    return profit;
  }
};
