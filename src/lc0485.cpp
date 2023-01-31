class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    auto last{-1}, longest{0}, i{0};
    for (; i < nums.size(); ++i) {
      if (!nums[i]) {
        longest = std::max(longest, i - last - 1);
        last = i;
      }
    }
    return std::max(longest, i - last - 1);
  }
};
