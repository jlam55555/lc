class Solution {
public:
  // bottom-up dp
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < amount; ++i) {
      if (dp[i] == INT_MAX) {
        continue;
      }

      for (int coin : coins) {
        if (coin > amount)
          continue;

        int next = i + coin;
        if (next <= amount) {
          dp[next] = min(dp[next], dp[i] + 1);
        }
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};
