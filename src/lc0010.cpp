class Solution {
public:
  // based on
  // https://leetcode.com/problems/regular-expression-matching/discuss/5684/
  // very elegant dp recurrence relations
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    bool dp[21][31] = {1};
    for (int i = 0; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] =
              dp[i][j - 2] ||
              (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        } else {
          dp[i][j] = i && dp[i - 1][j - 1] &&
                     (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
      }
    }
    return dp[m][n];
  }
};
