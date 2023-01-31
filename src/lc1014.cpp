class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {

    // vector<int> dp(values.size());
    int prev, maxScore = INT_MIN;

    for (int j = values.size() - 1; j >= 1; --j) {
      int tmp = values[j] - j;
      if (j == values.size() - 1 || tmp > prev) {
        prev = tmp;
      }

      maxScore = max(maxScore, values[j - 1] + j - 1 + prev);
    }

    return maxScore;
  }
};
