// `n` numbers in the array, `m` queries.
//
// Both `n` and `m` are fairly small (<= 500).
// Try brute force? (This works, and it's
// annoying to try a solution with precomputation.)
//
// One optimization we can make is given by
// @votrubac's answer, in which we check the
// arithmetic sequence without sorting. This
// will make the algorithm O(mn) rather than
// O(mn*log(n)).
class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                        vector<int> &r) {
    int n(nums.size()), m(l.size());
    std::vector<bool> res;
    for (int i{}; i < m; ++i) {
      std::vector<int> copy(nums.begin() + l[i], nums.begin() + r[i] + 1);
      std::sort(copy.begin(), copy.end());
      bool arithmetic{true};
      for (int j{2}, end(copy.size()); j < end; ++j) {
        if (copy[j] - copy[j - 1] != copy[1] - copy[0]) {
          arithmetic = false;
          break;
        }
      }
      res.push_back(arithmetic);
    }
    return res;
  }
};
