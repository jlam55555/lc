class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {

    int maxSum = INT_MIN, curSum1 = 0, minSum = INT_MAX, curSum2 = 0, total = 0;

    // if max subarray bridges the gap, then it is separated
    // by the minsubarray in the middle;
    // the general max/min subarray algorithm is called
    // kadane's algorithm
    for (auto i : nums) {
      curSum1 = i + max(curSum1, 0);
      maxSum = max(maxSum, curSum1);
      curSum2 = i + min(curSum2, 0);
      minSum = min(minSum, curSum2);
      total += i;
    }

    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
  }
};
