class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int i, j;
    for (int i = j = 0; i < nums.size();) {
      if (!i || nums[i] != nums[i - 1]) {
        nums[j++] = nums[i];
      }
      ++i;
    }
    return j;
  }
};
