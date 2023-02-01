class Solution {
public:
  // Algorithm: find the left and right boundaries of
  // the "unsorted subarray" using the following intuition:
  // - The right side of the unsorted subarray should be marked
  //   by the largest unsorted element m (the largest element that
  //   is followed by a smaller element) if the array was sorted.
  // - Thus we look for the first element that is >= m and occurs
  //   later than m in the subarray.
  // - Alternatively, we can do the same by looking for the last
  //   element smaller than the maximum element seen so far.
  //   (This step inspired by @compton_scatter's solution.)
  // - To find the left side of this subarray, do the same
  //   thing in reverse.
  //
  // This is O(n) time and O(1) space.
  int findUnsortedSubarray(vector<int> &nums) {

    // Solution is marked by subarray [l, r). If there is no
    // such subarray (i.e., array is sorted), then l=r=0.
    int len(nums.size()), l{}, r{}, min{INT_MAX}, max{INT_MIN};
    for (int i{}; i < nums.size(); ++i) {

      // Update right side of subarray.
      max = std::max(max, nums[i]);
      if (nums[i] < max) {
        r = i + 1;
      }

      // Update left side of subarray.
      min = std::min(min, nums[len - 1 - i]);
      if (nums[len - 1 - i] > min) {
        l = len - 1 - i;
      }
    }

    return r - l;
  }
};
