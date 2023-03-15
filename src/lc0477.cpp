// Every bit is orthogonal to every other bit.
// Thus we can compute the Hamming distance sum for
// the kth bit, and then sum together the results for
// all k in [0, 32).
//
// So now consider a single bit:
// If the kth bit is set in m elements of nums, and not
// set in l=n-m elements. How many bit differences would
// this be? Breaking the Cartesian product down into cases:
// - n cases of choosing the same number twice
// - m*(m-1) cases of kth bit set in both nums
// - l*(l-1) cases of kth bit not set in both nums
// - m*l cases of kth bit being different
//
// Note: this question has a similar feel to lc1863.cpp.
// I actually found this question easier than that one,
// even though this is rated as a medium on Leetcode and
// lc1863.cpp is rated as an easy question.
class Solution {
public:
  int totalHammingDistance(vector<int> &nums) {
    // Count the number of bits set for each bit.
    int num_bits_set[32]{}, *num_bits_set_p(num_bits_set), n(nums.size());
    for (unsigned mask{1}; mask; mask <<= 1, ++num_bits_set_p) {
      for (auto n : nums) {
        *num_bits_set_p += !!(n & mask);
      }
    }

    // Count the number of bit differences for each bit.
    int res{};
    for (int i{}; i < 32; ++i) {
      res += num_bits_set[i] * (n - num_bits_set[i]);
    }
    return res;
  }
};
