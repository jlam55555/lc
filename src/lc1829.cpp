// The question is very confusingly worded, but we basically need
// to get (XOR(nums[0:n-i]) xor 2^maximumBit) for i=1,2,...,n-1.
//
// It's a little more efficient to do this in reverse. We can also
// do it in-place to save memory.
class Solution {
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    for (int i{}, n(nums.size()), cum_xor{}, mask{(1 << maximumBit) - 1}; i < n;
         ++i) {
      nums[i] = (cum_xor ^= nums[i]) ^ mask;
    }
    std::reverse(nums.begin(), nums.end());
    return nums;
  }
};
