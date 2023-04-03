// For each sum nums[0:i], we want to find the
// smallest j >= i s.t. (nums[0:i+1] + nums[j:n]) % p == 0.
// In other words, we are looking for a sum p-nums[0:i]
// when going in the reverse direction. The length of the
// array to remove is j-(i+1).
//
// This solution is inelegant but it works. This finds
// the sums of two outer subarrays rather than the sum
// of an inner subarray as @lee215 does; his solution is
// arguably better, but I'll leave my solution as-is.
class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    // Compute prefix sums.
    int n(nums.size());
    std::vector<int> pre(n + 1);
    for (int i{}; i < n; ++i) {
      pre[i + 1] = (pre[i] + nums[i]) % p;
    }

    // Go in reverse.
    std::unordered_map<int, int> post{{0, n}};
    int res{n}, rev_sum{};
    for (int i{n}; i >= 0; --i) {
      auto complement{(p - pre[i]) % p};
      if (post.count(complement)) {
        res = std::min(res, post[complement] - i);
      }
      post[rev_sum] = i;
      if (i) {
        rev_sum = (rev_sum + nums[i - 1]) % p;
      }
    }
    return res < n ? res : -1;
  }
};
