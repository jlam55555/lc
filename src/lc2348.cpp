// Standard counting problem. If we have a subarray of
// zeros of length k, then this subarray contains:
// - k subarrays of zeros of length 1
// - k-1 subarrays of zeros of length 2
// - k-2 subarrays of zeros of length 3
// - ...
// - 1 subarray of zeros of length k
//
// In sum, there are sum(1...k) = k(k+1)/2 subarrays
// of arbitrary length contained within a larger subarray
// of length k.
//
// The editorial has a slightly different way of counting but
// these should be equivalent.
class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long res{};
    for (int i{}, n(nums.size()); i < n;) {
      while (i < n && nums[i] != 0) {
        ++i;
      }
      int j{i};
      while (j < n && nums[j] == 0) {
        ++j;
      }
      res += long(j - i) * (j - i + 1) / 2;
      i = j;
    }
    return res;
  }
};
