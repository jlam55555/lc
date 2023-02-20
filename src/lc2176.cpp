class Solution {
public:
  int countPairs(vector<int> &nums, int k) {
    int res{};
    for (int i{}; i < nums.size(); ++i) {
      for (int j{i + 1}; j < nums.size(); ++j) {
        res += nums[i] == nums[j] && !(i * j % k);
      }
    }
    return res;
  }
};
