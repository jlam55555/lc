class Solution {
public:
  vector<int> getConcatenation(vector<int> &nums) {
    for (int i{}, n(nums.size()); i < n; ++i) {
      nums.push_back(nums[i]);
    }
    return nums;
  }
};
