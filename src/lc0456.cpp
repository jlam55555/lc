class Solution {

public:
  // use monotonic stack
  bool find132pattern(vector<int> &nums) {
    if (!nums.size())
      return 0;

    // find lowest up until each point
    int len = nums.size(), i, top, j;
    int *lowestUpTill = new int[len];
    lowestUpTill[0] = nums[0];
    for (int i = 1; i < len; ++i)
      lowestUpTill[i] = ::min(lowestUpTill[i - 1], nums[i]);

    // find previous element larger than
    // alternative to the below code, but slower
    // int *prevLarger = new int[len];
    // prevLarger[0] = -1;
    // for (i = 1; i < len; ++i) {
    //     j = i-1;
    //     while (j > 0 && nums[j] <= nums[i])
    //         j = prevLarger[j];
    //     prevLarger[i] = j;
    //     if (j > 0 && lowestUpTill[j] < nums[i])
    //         return true;
    // }

    // stack will be monotonically decreasing
    for (i = len - 1, top = len; i >= 0; --i) {
      while (top < len && nums[i] > nums[top])
        if (lowestUpTill[i] < nums[top++])
          return true;
      nums[--top] = nums[i];
    }

    return false;
  }
};
