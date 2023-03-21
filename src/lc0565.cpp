// This question asks us to find the longest permutation cycle.
// Thus we simply iterate through permutation cycles (and
// mark them to avoid going through a permutation cycle
// multiple times.)
class Solution {
public:
  int arrayNesting(vector<int> &nums) {
    int res{};
    for (int i{}, n(nums.size()); i < n; ++i) {
      // Traverse the permutation cycle that contains
      // i, if we haven't seen it already.
      if (nums[i] == -1) {
        continue;
      }

      int j{i}, cycle_len{};
      do {
        std::tie(j, nums[j]) = std::make_pair(nums[j], -1);
        ++cycle_len;
      } while (j != i);
      res = std::max(res, cycle_len);
    }
    return res;
  }
};
