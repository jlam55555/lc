class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    // first val is if you robbed the previous house,
    // second val is if you didn't rob the previous house
    int vals[2] = {nums[0], max(nums[0], nums[1])};

    for (int i = 2; i < nums.size(); ++i) {
      int tmp = max(vals[1], vals[0] + nums[i]);
      vals[0] = vals[1];
      vals[1] = tmp;
    }

    return vals[1];
  }
};
