// Classic Knapsack 0-1 with a bitwise optimization.
// There is also a DP solution, but this is simpler and
// more space efficient when the total is bounded
// (so that we can use a fixed-size bitset) and we
// don't need to count how many solutions there.
class Solution {
public:
  bool subset_sum(::vector<int> &values, int sum) {
    bitset<16384> dp{1};
    for (auto i : values) {
      dp |= dp << i;
    }
    return dp[sum];
  }

  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto i : nums) {
      sum += i;
    }

    if (sum % 2) {
      return false;
    }

    return subset_sum(nums, sum / 2);
  }
};
