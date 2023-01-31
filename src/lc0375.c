int dp[201][201] = {0};

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int getMoneyAmount(int n) {
  int len, start, split, cost, minSplitCost;

  for (len = 2; len <= n; ++len) {
    for (start = 0; start <= n - len; ++start) {
      for (split = 0, minSplitCost = 1000000000; split < len; ++split) {
        cost = max(dp[start][split], dp[start + split + 1][len - split - 1]) +
               start + split + 1;
        minSplitCost = min(minSplitCost, cost);
      }
      dp[start][len] = minSplitCost;
    }
  }

  return dp[0][n];
}
