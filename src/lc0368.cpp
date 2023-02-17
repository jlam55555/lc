class Solution {
public:
  // DP Problem.
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n(nums.size());

    // `dp` holds the length of the longest chain ending
    // at `nums[i]`
    std::vector<int> dp(n, 1);

    // `parents` holds the parent of `nums[i]` in the
    // longest chain.
    std::vector<int> parents(nums.size());
    for (int i{}; i < n; ++i) {
      parents[i] = i;
    }

    // Run dp.
    for (int i{}; i < n; ++i) {
      for (int j{}; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          parents[i] = j;
        }
      }
    }

    // Reconstruct longest chain.
    int it(std::distance(dp.begin(), std::max_element(dp.begin(), dp.end())));
    std::vector<int> res{nums[it]};
    while (parents[it] != it) {
      res.push_back(nums[it = parents[it]]);
    }
    return res;
  }
};
