// 1 => one 1
// 1 2 => two 2s
// 1 2 2 => two 1s
// 1 2 2 1 (1) => one 2 <-- next number generated alternates
// 1 2 2 1 1 (2) => one 1
// 1 2 2 1 1 2 (1) => two 2s
// 1 2 2 1 1 2 1 (2 2) => one 1
// 1 2 2 1 1 2 1 2 (2 1) => two 2s
// 1 2 2 1 1 2 1 2 2 (1 2 2) => one 1
//                 ^ current generator = i
// next insertion point = j ^
//
// For simplicity, we encode 1 as true
// and 2 as false. This is pretty arbitrary.
class Solution {
public:
  int magicalString(int n) {
    // Avoid a messy accumulate.
    if (n <= 3) {
      return 1;
    }

    // Only start counting at i=2, j=3.
    // n+1 here is to avoid a bounds check in the
    // `if(!dp[i]) {...}` condition.
    std::vector<bool> dp(n + 1);
    dp[0] = 1;
    int res{1}, i{2};
    for (int j{3}, next{true}; j < n; next ^= 1, ++i) {
      res += dp[i];
      dp[j++] = next;
      !dp[i] && (dp[j++] = next);
    }

    // Count the remainder of the numbers.
    return std::accumulate(dp.begin() + i, dp.begin() + n, res);
  }
};
