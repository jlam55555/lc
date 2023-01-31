class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    // go from back to front, find first consecutive pair of numbers that are
    // "in order", swap the last inorder part with the first number larger than
    // it, reverse the remaining part
    int i, j, len;
    for (len = nums.size(), i = len - 1; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        // search for first number in nums[i...end] that is larger than nums[j]
        for (j = len - 1; nums[j] <= nums[i - 1]; --j)
          ;

        ::swap(nums[j], nums[i - 1]);
        ::reverse(nums.begin() + i, nums.end());
        return;
      }
    }

    // if here is reached, that means no next permutation
    ::reverse(nums.begin(), nums.end());
  }
};
