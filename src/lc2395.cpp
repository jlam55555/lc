class Solution {
public:
  bool findSubarrays(vector<int> &nums) {
    std::unordered_set<int> sums;
    for (int i{}, n(nums.size()); i < n - 1; ++i) {
      int sum{nums[i] + nums[i + 1]};
      if (sums.count(sum)) {
        return true;
      }
      sums.insert(sum);
    }
    return false;
  }
};
