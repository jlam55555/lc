// This is simply a counting problem.
//
// How many different 4-tuples with the same four numbers
// and the constrains specified in the problems.
// 4 * 1 * 2 * 1 = 8 different ways
//
// If we have k pairs of numbers that multiply to some
// product p, then we can generate kC2 4-tuples.
class Solution {
public:
  int tupleSameProduct(vector<int> &nums) {
    // Count frequencies of all products.
    std::unordered_map<int, int> prods;
    for (int i{}, n(nums.size()); i < n; ++i) {
      for (int j{i + 1}; j < n; ++j) {
        ++prods[nums[i] * nums[j]];
      }
    }

    // Count.
    int res{};
    for (auto [unused, freq] : prods) {
      res += freq * (freq - 1) / 2;
    }
    return res * 8;
  }
};
