class Solution {
public:
  int arrayPairSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    auto sum{0};
    for (auto i{0}; i < nums.size(); i += 2) {
      sum += nums[i];
    }
    return sum;
  }
};
