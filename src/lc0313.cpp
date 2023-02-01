class Solution {
public:
  // Generalized version of Ugly Number II.
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    int l = primes.size();
    std::vector<int> ind(l);
    std::vector<long> dp(n);

    dp[0] = 1;
    for (int i{1}; i < n; ++i) {
      long next{INT_MAX};
      for (int j{}; j < l; ++j) {
        next = std::min(next, dp[ind[j]] * primes[j]);
      }
      for (int j{}; j < l; ++j) {
        if (dp[ind[j]] * primes[j] == next) {
          ++ind[j];
        }
      }
      dp[i] = next;
    }

    return dp[n - 1];
  }
};
