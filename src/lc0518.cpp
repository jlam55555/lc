// Very standard bottom-up DP problem. `dp[i]` represents the number
// of ways we can reach the amount `i` using the coins encountered
// so far.
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    std::vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int i{}, n(coins.size()); i < n; ++i) {
      for (int j{coins[i]}; j <= amount; ++j) {
        dp[j] += dp[j - coins[i]];
      }
    }
    return dp[amount];
  }
};
