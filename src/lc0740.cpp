class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    map<int, int> hist{};

    for (auto i : nums) {
      ++hist[i];
    }

    int dp[] = {0, 0}, prev = INT_MIN, tmp;
    for (auto freq : hist) {
      // cannot add previous one to the current one
      if (prev == freq.first - 1) {
        tmp = max(dp[1], dp[0] + freq.first * freq.second);
      }
      // can add the previous one to the current one
      else {
        tmp = max(dp[1], dp[0]) + freq.first * freq.second;
      }
      dp[0] = dp[1];
      dp[1] = tmp;
      prev = freq.first;
    }

    return dp[1];
  }
};
