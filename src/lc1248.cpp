class Solution {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    int len, leftMin, leftMax, right, minCount, maxCount, count;

    // find number of subarrays that
    for (len = nums.size(),
        leftMin = leftMax = right = minCount = maxCount = count = 0;
         right < len; ++right) {

      // shrink size of leftMin until it satisfies criteria
      minCount += nums[right] % 2;
      while (leftMin < right && minCount > k)
        minCount -= nums[leftMin++] % 2;

      // shrink size of leftMax until to make it satisfy criteria
      maxCount += nums[right] % 2;
      while (leftMax < right && maxCount - nums[leftMax] % 2 >= k)
        maxCount -= nums[leftMax++] % 2;

      // if criteria is met, add here
      if (maxCount == k)
        count += leftMax - leftMin + 1;
    }

    return count;
  }
};
