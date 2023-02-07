class Solution {
public:
  // I wouldn't say this solution is easy. The mathematical
  // explanation is here:
  // https://leetcode.com/problems/sum-of-all-subset-xor-totals/solutions/1211213
  int subsetXORSum(vector<int> &nums) {
    int res{};
    for (auto n : nums) {
      res |= n;
    }
    return res << (nums.size() - 1);
  }
};
