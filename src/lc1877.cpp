class Solution {
public:
  int minPairSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int res{};
    for (int i{}, n(nums.size()); i < n / 2; ++i) {
      res = std::max(res, nums[i] + nums[n - 1 - i]);
    }
    return res;
  }
};
