class Solution {
public:
  int countQuadruplets(vector<int> &nums) {
    int n = nums.size(), count = 0;

    for (int d = 3; d < n; ++d) {
      for (int c = 2; c < d; ++c) {
        for (int b = 1; b < c; ++b) {
          for (int a = 0; a < b; ++a) {
            count += nums[a] + nums[b] + nums[c] == nums[d];
          }
        }
      }
    }

    return count;
  }
};
