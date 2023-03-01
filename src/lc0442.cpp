class Solution {
public:
  // Algorithm: try to put each number in its correct
  // location, and count the ones that are out of place.
  vector<int> findDuplicates(vector<int> &nums) {
    int n(nums.size());
    for (int i{}; i < n; ++i) {
      while (nums[nums[i] - 1] != nums[i]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }

    std::vector<int> res;
    for (int i{}; i < n; ++i) {
      if (nums[i] != i + 1) {
        res.push_back(nums[i]);
      }
    }
    return res;
  }
};
