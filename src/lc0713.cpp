class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    // [l,r] inclusive window
    int prod = 1, res = 0;
    for (int l = 0, r = 0; r < nums.size(); ++r) {
      prod *= nums[r];
      while (l < r && prod >= k) {
        prod /= nums[l++];
      }

      if (prod < k) {
        res += r - l + 1;
      }
    }

    return res;
  }
};
