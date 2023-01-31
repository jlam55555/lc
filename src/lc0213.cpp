class Solution {
public:
  int rob(vector<int> &nums) {
    int dp[2] = {0, 0};

    // edge case; might not be necessary
    if (nums.size() == 1) {
      return nums[0];
    }

    // calculate string one -- using first house
    int ans1;
    for (int i = 0; i < nums.size() - 1; ++i) {
      int tmp = max(dp[1], dp[0] + nums[i]);
      dp[0] = dp[1];
      dp[1] = tmp;
    }

    ans1 = dp[1];

    dp[0] = dp[1] = 0;
    for (int i = 1; i < nums.size(); ++i) {
      int tmp = max(dp[1], dp[0] + nums[i]);
      dp[0] = dp[1];
      dp[1] = tmp;
    }

    return max(dp[1], ans1);
  }
};
