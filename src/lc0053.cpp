class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int curSum = 0, maxSum = INT_MIN;
    for (auto i : nums) {
      maxSum = max(maxSum, curSum += i);
      curSum = max(curSum, 0);
    }

    return maxSum;
  }
};
