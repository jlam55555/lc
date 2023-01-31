class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    // cumulative product from left and right
    vector<int> cpl(nums.size(), 1);

    cpl[0] = 1;
    for (int i = 0; i < nums.size() - 1; ++i) {
      cpl[i + 1] = cpl[i] * nums[i];
    }

    int cpr = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      cpl[i] *= cpr;
      cpr *= nums[i];
    }

    return cpl;
  }
};
