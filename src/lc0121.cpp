class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int maxPrice = INT_MIN, maxProfit = 0;
    for (int i = prices.size() - 1; i > 0; --i) {
      maxPrice = max(maxPrice, prices[i]);
      maxProfit = max(maxProfit, maxPrice - prices[i - 1]);
    }

    return maxProfit;
  }
};
