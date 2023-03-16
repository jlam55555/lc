#define TOTAL 1000

// The following is similar to @chidong's solution.
// This is very similar to the DP solution for the
// Knapsack 0-1 problem (see also: lc0282.cpp) if
// we need to count how many different ways there are
// to get to the target.
class Solution {
public:
  // Store the number of ways we can reach each sum using
  // the numbers we've seen so far.
  int dp_[2][2 * TOTAL + 1]{};

  int findTargetSumWays(vector<int> &nums, int target) {
    // Alternate between two arrays: `turn` represents the last
    // filled array, `turn^1` represents the array we're filling.
    // `sum` denotes the total sum of the elements so far.
    int turn{}, sum{};

    // Base case.
    dp_[turn][TOTAL] = 1;

    // Iterate.
    for (int num : nums) {
      for (int i{-sum}; i <= sum; ++i) {
        dp_[turn ^ 1][TOTAL + i + num] += dp_[turn][TOTAL + i];
        dp_[turn ^ 1][TOTAL + i - num] += dp_[turn][TOTAL + i];
      }

      // Only need to erase elements that we've seen so far,
      // i.e., in the range [-sum, sum].
      std::fill(dp_[turn] + TOTAL - sum, dp_[turn] + TOTAL + sum + 1, 0);
      sum += std::abs(num);
      turn ^= 1;
    }

    return dp_[turn][TOTAL + target];
  }
};
