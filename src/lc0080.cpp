class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int i{};
    for (int j{}; j < nums.size(); ++j) {
      // Copy if not more than two duplicates.
      if (i < 2 || nums[i - 2] < nums[j]) {
        nums[i++] = nums[j];
      }
    }
    return i;
  }
};
