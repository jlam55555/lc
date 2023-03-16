// We generate all the possible subsequences using a bitmask
// and then store duplicates in a set. Backtracking can also
// be used and can help us skip some bad prefixes, but we have
// a small enough search space (2^15 elements in the power set)
// that checking each element is okay, and this gives a simpler
// solution.
//
// I don't really like this solution, because it doesn't feel very
// elegant at all -- as @pnw999 says in their comment on the
// editorial, I thought for a while for a more elegant way to
// remove duplicates but couldn't think of any.
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    std::set<std::vector<int>> res;

    // Use tmp to store the subsequence to avoid dynamic
    // allocation with a vector each time. Only if the
    // subsequence is non-decreasing do we perform memory
    // allocation.
    int tmp[15], l;

    for (int i{}, n(nums.size()); i < (1 << n); ++i) {

      // Check if at least two bits set.
      if (!(i & (i - 1))) {
        continue;
      }

      l = 0;
      for (int j{}, mask{1}; j < n; ++j, mask <<= 1) {
        if (i & mask) {
          // Forms a non-decreasing subsequence.
          if (!l || nums[j] >= tmp[l - 1]) {
            tmp[l++] = nums[j];
          }
          // Doesn't form a non-decreasing subsequence, skip.
          else {
            goto continue_;
          }
        }
      }

      // Add vector to set.
      res.emplace(tmp, tmp + l);

    continue_:;
    }
    return {res.begin(), res.end()};
  }
};
