class Solution {
public:
  string longestPalindrome(string s) {

    int n = s.length();

    if (!n)
      return 0;

    // indexed by length, (starting index)
    bool dp[1001][1000] = {0};

    // all palindromes are of length 1
    int maxLen = 1, maxInd = 0;
    for (int i = 0; i < n; ++i) {
      dp[0][i] = dp[1][i] = 1;
    }

    // for each length from 2 .. n
    for (int i = 2; i <= n; ++i) {
      // starting index of palindrome
      for (int j = 0; j <= n - i; ++j) {
        if (dp[i - 2][j + 1] && s[j] == s[j + i - 1]) {
          dp[i][j] = 1;
          maxLen = i, maxInd = j;
        }
      }
    }

    return s.substr(maxInd, maxLen);
  }
};
