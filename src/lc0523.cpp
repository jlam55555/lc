// Use a prefix sum modulo k. If we've seen this sum
// before (more than one element ago), then we have a good
// subarray.
//
// I felt real big-brained coming up with this, which
// solves the problem of how we simultaneously check
// all multiples of k in the prefix sum.
class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    int cum_sum_mod_k{};
    std::unordered_map<int, int> seen;
    seen[0] = -1;
    for (int i{}, n(nums.size()); i < n; ++i) {
      cum_sum_mod_k = (cum_sum_mod_k + nums[i]) % k;
      if (auto it{seen.find(cum_sum_mod_k)}; it != seen.end()) {
        if (it->second < i - 1) {
          return true;
        }
      } else {
        seen[cum_sum_mod_k] = i;
      }
    }
    return false;
  }
};
