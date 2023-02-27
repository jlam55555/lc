class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    std::unordered_map<int, int> freqs;
    int res{};
    for (int i{}, n(nums.size()); i < n; ++i) {
      res += std::min(freqs[nums[i] - diff], freqs[nums[i] - diff * 2]);
      ++freqs[nums[i]];
    }
    return res;
  }
};
