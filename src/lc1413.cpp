class Solution {
public:
  int minStartValue(vector<int> &nums) {
    int cumSum = 0;
    int minCumSum = INT_MAX;

    for (auto i : nums) {
      cumSum += i;
      minCumSum = min(minCumSum, cumSum);
    }

    return max(1, 1 - minCumSum);
  }
};
