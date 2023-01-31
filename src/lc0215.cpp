class Solution {
public:
  // Quickselect.
  int findKthLargest(std::vector<int> &nums, int k, int l, int r) {
    int pivot = nums[r - 1], i{}, j{};
    for (; l + i < r - 1; ++i) {
      if (nums[l + i] > pivot) {
        std::swap(nums[l + j++], nums[l + i]);
      }
    }
    std::swap(nums[l + j], nums[r - 1]);

    return j == k  ? nums[l + j]
           : j > k ? findKthLargest(nums, k, l, l + j)
                   : findKthLargest(nums, k - (j + 1), l + j + 1, r);
  }

  int findKthLargest(vector<int> &nums, int k) {
    return findKthLargest(nums, k - 1, 0, nums.size());
  }
};
