class Solution {
public:
  void moveZeroes(vector<int> &nums) {

    // i points to the next character to read
    // j points to the next place to insert a non-zero character
    int i, j;
    for (i = j = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nums[j++] = nums[i];
      }
    }

    for (; j < nums.size(); ++j) {
      nums[j] = 0;
    }
  }
};
