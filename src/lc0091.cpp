class Solution {
public:
  // dp problem with fixed lookahead
  int numDecodings(string s) {
    int dp[2] = {1, 0}, prev, curr;
    char c;

    // loop invariant:
    // dp[0] is the number of known paths to s[i]
    // dp[1] is the number of known paths to s[i+1]
    for (int i = 0; i < s.length(); ++i) {
      // calculate (new) ways to get to s[i+1],
      // ways to get to s[i+2] knowing s[i], s[i+1]
      c = s[i], prev = dp[0], curr = dp[1];

      dp[0] = curr;
      dp[1] = 0;

      if (c == '0') {
        // no ways to advance
      } else {
        dp[0] += prev;

        if (i < s.length() - 1 && (c < '2' || c == '2' && s[i + 1] < '7')) {
          dp[1] += prev;
        }
      }
    }

    return dp[0];
  }
};
