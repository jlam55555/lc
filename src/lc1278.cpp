class Solution {
public:
  int palindromePartition(string s, int k) {

    int len = s.length();

    // toPal[j][i] = the number of changes needed to make the substring
    // s(j, i) (j <= i, i and j are inclusive) into a palindrome
    int **toPal = new int *[len];
    for (int i = 0; i < len; ++i) {
      toPal[i] = new int[len];
      ::fill(toPal[i], toPal[i] + len, 0);
    }

    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < i; ++j) {

        // we have a substring of length i-j+1
        // need to check if s[j+k] == s[i-k], 0 <= k < (i-j+1)/2
        int count = 0;
        for (int l = 0; l < (i - j + 1) / 2; ++l) {
          count += s[j + l] != s[i - l];
        }

        toPal[j][i] = count;
      }
    }

    int **dp = new int *[len];
    for (int i = 0; i < len; ++i) {
      dp[i] = new int[len];
      ::fill(dp[i], dp[i] + len, 0);
    }

    // potential edge case: input length is 0

    // fill out base case
    // dp[0][endIndex] = toPal[0][endIndex];
    for (int endIndex = 0; endIndex < len; ++endIndex) {
      dp[0][endIndex] = toPal[0][endIndex];
    }

    // dp[numSets][endIndex] = min_{0 <= i < endIndex}{dp[numSets-1][i] +
    // toPal[i+1][endIndex]}
    for (int numSets = 1; numSets < k; ++numSets) {
      for (int endIndex = numSets; endIndex < len; ++endIndex) {
        int minDp = INT_MAX;
        for (int i = 0; i < endIndex; ++i) {
          minDp = ::min(minDp, dp[numSets - 1][i] + toPal[i + 1][endIndex]);
        }
        dp[numSets][endIndex] = minDp;
      }
    }

    // delete toPal, dp
    int res = dp[k - 1][len - 1];

    for (int i = 0; i < len; ++i) {
      delete[] dp[i];
      delete[] toPal[i];
    }
    delete[] dp;
    delete[] toPal;

    return res;
  }
};
