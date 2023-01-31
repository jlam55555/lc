class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {

    // mark array to indicate which numbers are missing
    // we can mark numbers by making them nonpositive
    // to do this, we start by making all nonpositive numbers something else
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= 0) {
        nums[i] = INT_MAX;
      }
    }

    // now do the actual thing
    for (int i = 0; i < nums.size(); ++i) {
      if (abs(nums[i]) - 1 < nums.size() && nums[abs(nums[i]) - 1] > 0) {
        nums[abs(nums[i]) - 1] *= -1;
      }
    }

    // find the first nonnegative index
    int i;
    for (i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }

    return i + 1;
  }
};
