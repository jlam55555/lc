class Solution {
public:
  int minMaxGame(vector<int> &nums) {
    for (int i{}, n(nums.size()), rounds(std::log2(n)); i < rounds; ++i) {
      for (int j{}, k{}, diff{1 << i}; j < n; j += 2 * diff, ++k) {
        nums[j] = k & 1 ? std::max(nums[j], nums[j + diff])
                        : std::min(nums[j], nums[j + diff]);
      }
    }
    return nums[0];
  }
};
