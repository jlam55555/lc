class Solution {
public:
  int longestArithSeqLength(vector<int> &A) {
    int k = A.size(), longest = 0, diff, i, j;

    // dp[lastIndex][diff] = len
    int *dp = new int[k << 10];
    ::fill(dp, dp + (k << 10), 0);

    for (i = 1; i < k; ++i)
      for (j = 0; j < i; diff = (A[i] - A[j]) + 500,
          longest = max(longest,
                        dp[(i << 10) + diff] = dp[(j << 10) + diff] + 1),
          ++j)
        ;

    return longest + 1;
  }
};
