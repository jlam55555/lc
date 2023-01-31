class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // profit if currently held/sold before index i
    int if_hold = 0, if_sold = 0;

    for (int i = 0; i < prices.size() - 1; ++i) {
      int if_hold_tmp = max(if_hold + prices[i + 1] - prices[i], if_sold);
      if_sold = max(if_hold, if_sold);
      if_hold = if_hold_tmp;
    }

    return max(if_hold, if_sold);
  }
};

// before index i, either hold or sold
// at index i+1:
// if previously hold  ->
//     keep holding    -> if_hold + prices[i+1]-prices[i]
//     sell            -> if_hold
// if previously sold  ->
//     buy             -> if_sold
//     keep sold       -> if_sold
