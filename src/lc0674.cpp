class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    auto rval{INT_MIN};
    for (auto i{0}; i < nums.size();) {
      auto j{i + 1};
      while (j < nums.size() && nums[j] > nums[j - 1])
        ++j;
      rval = std::max(rval, j - i);
      i = j;
    }
    return rval;
  }
};
