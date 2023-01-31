class Solution {
public:
  int dfs(vector<int> &stones, int l, int r, int sum, int turn,
          int dp[1001][1001]) {
    // memoization
    if (dp[l][r] || l == r) {
      return dp[l][r];
    }

    // attempt to maximize the score
    int score1 = turn * (sum - stones[l]) +
                 dfs(stones, l + 1, r, sum - stones[l], -turn, dp),
        score2 = turn * (sum - stones[r - 1]) +
                 dfs(stones, l, r - 1, sum - stones[r - 1], -turn, dp);

    return dp[l][r] = turn == 1 ? max(score1, score2) : min(score1, score2);
  }

  int stoneGameVII(vector<int> &stones) {
    int totalSum = 0;
    for (int i : stones) {
      totalSum += i;
    }

    // indexed by start position, end position
    // dp[i][j] indicates score difference if played best
    int dp[1001][1001] = {0};
    return dfs(stones, 0, stones.size(), totalSum, 1, dp);
  }
};
