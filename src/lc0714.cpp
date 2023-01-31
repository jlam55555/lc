class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int if_hold = 0, if_sold = 0;

    for (int i = 0; i < prices.size(); ++i) {
      int tmp = if_hold;
      if_sold = max(if_hold - fee, if_sold);

      if (i < prices.size() - 1) {
        if_hold = max(tmp + prices[i + 1] - prices[i], if_sold);
      }
    }

    return if_sold;
  }
};

// 1 3 7 5 10 3
// (10-1)-3

// change
// if hold:
//     hold -> prices[i+1]-prices[i]
//     sell -> -fee
// if sold:
//     buy  -> 0
//     sold -> 0
