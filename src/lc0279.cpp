class Solution {
public:
  int numSquares(int n) {
    std::vector<int> squares;
    for (int i{1}; i * i <= n; ++i) {
      squares.push_back(i * i);
    }
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i{1}; i <= n; ++i) {
      for (auto sq : squares) {
        if (i - sq < 0) {
          break;
        }
        dp[i] = std::min(dp[i - sq] + 1, dp[i]);
      }
    }
    return dp[n];
  }
};
