class Solution {
public:
  int minOperations(vector<int> &nums, int x) {

    if (x == 0) {
      return 0;
    }

    // find maximum subarray that sums to (total-x)
    int total = 0;
    for (int i : nums) {
      total += i;
    }

    int target = total - x;

    // try to find maximum window length that sums to total - x
    unordered_map<int, int> cumSums{{0, -1}};

    int cumSum = 0;
    int maxWindow = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      cumSums[cumSum += nums[i]] = i;

      // window found if cumSum - other == target
      // thus other = cumSum - target
      if (cumSums.count(cumSum - target)) {
        maxWindow = max(maxWindow, i - cumSums[cumSum - target]);
      }
    }

    return maxWindow == INT_MIN ? -1 : nums.size() - maxWindow;
  }
};
