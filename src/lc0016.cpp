class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int i, j, k, len = nums.size(), sum, sum2, sum3, closestDiff = 1000000,
                 closestSum = -1;

    ::sort(nums.begin(), nums.end());

    for (i = 0; i < len - 2; ++i) {
      for (j = i + 1, k = len - 1; j < k;) {
        sum = nums[i] + nums[j] + nums[k];

        if (abs(sum - target) < closestDiff) {
          if (sum == target)
            return sum;

          closestDiff = abs(sum - target);
          closestSum = sum;
        }

        // try to get closer
        if (sum < target) {
          while (j < k && nums[j] == nums[j + 1])
            ++j;
          ++j;
        } else {
          while (j < k && nums[k] == nums[k - 1])
            --k;
          --k;
        }
      }
    }

    return closestSum;
  }
};
