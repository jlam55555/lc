// Classic sliding-window problem. Keep track of the longest window
// possible with unique characters.
class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    // Build initial window.
    int l{}, r{}, n(nums.size()), sum{};
    std::bitset<10001> seen;
    while (r < n && !seen.test(nums[r])) {
      sum += nums[r];
      seen.set(nums[r++]);
    }

    // Slide window.
    int res{sum};
    while (r < n) {
      sum -= nums[l];
      seen.reset(nums[l++]);
      while (r < n && !seen.test(nums[r])) {
        sum += nums[r];
        seen.set(nums[r++]);
      }
      res = std::max(res, sum);
    }

    return res;
  }
};
