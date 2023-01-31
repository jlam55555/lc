class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {

    // left and right of sliding window (inclusive)
    int l, r, cur_sum, min_width;

    for (l = r = cur_sum = 0, min_width = INT_MAX; r < nums.size(); ++r) {
      cur_sum += nums[r];

      // window start slide right
      while (l < r && cur_sum - nums[l] >= target) {
        cur_sum -= nums[l++];
      }

      // new min_width; if condition is false, we must
      // be at  the end of the array
      if (cur_sum >= target) {
        min_width = min(min_width, r - l + 1);
      }
    }

    // if min_width == INT_MAX then we haven't found a solution
    return min_width == INT_MAX ? 0 : min_width;
  }
};
