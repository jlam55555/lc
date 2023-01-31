class Solution {
public:
  // for our purposes, range is [start, end)
  double mean(vector<int> &v, int start, int end) {
    double sum = 0;
    for (int i = start; i < end; ++i)
      sum += v[i];
    return sum / (end - start);
  }

  double largestSumOfAverages(vector<int> &A, int K) {

    // if K >= len(A), break into len(A) subsets, this is maximum
    // should also take care of trivial case when len(A) == 0
    if (K >= A.size()) {
      int sum = 0;
      for (int i : A)
        sum += i;
      return sum;
    }

    vector<vector<double>> means(A.size(), vector<double>(A.size()));
    for (int i = 0; i < A.size(); ++i)
      for (int j = 0; j <= i; ++j)
        means[j][i] = mean(A, j, i + 1);

    // dp[k][end]
    vector<vector<double>> dp(K, vector<double>(A.size()));

    double currMax;

    // set up dp array
    // dp[0][i] is scores (averages) for s[0:i+1],
    // dp[1][i] is scores for k=2, etc.
    for (int i = 0; i < A.size(); ++i)
      dp[0][i] = means[0][i];

    for (int k = 1; k < K; ++k)
      for (int i = k; i < A.size(); ++i) {
        currMax = 0;
        for (int j = 0; j < i; ++j)
          currMax = max(currMax, dp[k - 1][j] + means[j + 1][i]);
        dp[k][i] = currMax;
      }

    // solution is at dp[K-1][len(A)-a]
    return dp[K - 1][A.size() - 1];
  }
};
