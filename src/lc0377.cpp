class Solution {
public:
  // Coin change problem. DP solution.
  int combinationSum4(vector<int> &nums, int target) {
    // Unsigned may be a bit unorthodox. It allows for
    // (unchecked) overflow/wraparound. But since the
    // question guarantees that there'll be no overflow,
    // this shouldn't affect our answer.
    std::vector<unsigned> dp(target + 1);
    dp[0] = 1;

    for (int i{}; i < target; ++i) {
      for (int j : nums) {
        if (i + j <= target) {
          dp[i + j] += dp[i];
        }
      }
    }

    return dp[target];
  }
};
