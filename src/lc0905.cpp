class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    auto l{0}, r{int(nums.size()) - 1};
    while (l < r) {
      // Advance l to an odd number.
      while (l < r && !(nums[l] & 1)) {
        ++l;
      }
      // Advance r to an even number.
      while (l < r && (nums[r] & 1)) {
        --r;
      }
      if (l < r) {
        std::swap(nums[l], nums[r]);
      }
    }
    return nums;
  }
};
