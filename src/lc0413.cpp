class Solution {
public:
  int countSlices(int n) { return n * (n + 1) >> 1; }

  int numberOfArithmeticSlices(vector<int> &nums) {

    int currLen = 0, slices = 0;
    for (int i = 2; i < nums.size(); ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        ++currLen;
      } else {
        slices += countSlices(currLen);
        currLen = 0;
      }
    }

    return slices + countSlices(currLen);
  }
};
