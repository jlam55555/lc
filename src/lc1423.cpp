class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    // find the smallest sum for l-k
    int totalSum = 0, minKSum = INT_MAX, curKSum = 0;

    int i, n = cardPoints.size();
    for (i = 0; i < n - k; ++i) {
      curKSum += cardPoints[i];
      totalSum += cardPoints[i];
    }
    minKSum = curKSum;

    for (; i < cardPoints.size(); ++i) {
      totalSum += cardPoints[i];

      // new min sum that ends at i
      curKSum += cardPoints[i] - cardPoints[i - (n - k)];
      minKSum = min(minKSum, curKSum);
    }

    return totalSum - minKSum;
  }
};
