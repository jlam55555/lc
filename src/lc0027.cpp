class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int i, j;
    for (i = 0, j = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[j++] = nums[i];
      }
    }

    return j;
  }
};
