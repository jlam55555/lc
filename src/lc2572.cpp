// Note that a square-free subset cannot subsume a non-square-free
// subset. We can try brute-forcing square-free subsets.
//
// To check whether a new element can be added to a subset,
// it must have none of the same factors as any of the previous
// elements (except 1), and it must also not be a square element.
//
// Notes and simplifying observations:
// - We cannot have duplicate elements in a square-free subset.
// - The largest number is 30. That means the largest prime factor
//   we can have is 29. We can also hand-factor each number if we wanted.
// - We need to be careful with the factors 1 and n itself.
//
// Now that I think about it, we only need to check the presence
// of a factor in any of the integers that comprise the set,
// which leads me to think of a much more optimized bitmask solution.
// Each number is assigned a bitmask stating its primes.
//
// I would classify this as a Leetcode hard problem, as it took me
// a long time to get this solution to its final form. As @votrubac
// points out in his solution, this is basically a knapsack 0-1 problem
// (the "Generate all possibilities" section), but it took a long
// time for me to formulate the question as such.
#define MOD 1000000007
class Solution {

  // Could have (should have) precomputed this using
  // a constexpr function. But I did it by hand anyways.
  static constexpr const unsigned factors_[31]{
      0, // 0
      0, // 1's are treated specially
      0b00000000000000000000000000000010,
      0b00000000000000000000000000000100,
      0,
      0b00000000000000000000000000010000,
      0b00000000000000000000000000000110,
      0b00000000000000000000000001000000,
      0,
      0,
      0b00000000000000000000000000010010, // 10
      0b00000000000000000000010000000000,
      0,
      0b00000000000000000001000000000000,
      0b00000000000000000000000001000010,
      0b00000000000000000000000000010100,
      0,
      0b00000000000000010000000000000000,
      0,
      0b00000000000001000000000000000000,
      0, // 20
      0b00000000000000000000000001000100,
      0b00000000000000000000010000000010,
      0b00000000010000000000000000000000,
      0,
      0,
      0b00000000000000000001000000000010,
      0,
      0,
      0b00010000000000000000000000000000,
      0b00000000000000000000000000010110, // 30
  };

public:
  int squareFreeSubsets(vector<int> &nums) {
    // Count numbers and ones.
    std::vector<int> freqs(31);
    int ones{};
    for (auto num : nums) {
      if (factors_[num]) {
        ++freqs[num];
      } else if (num == 1) {
        ++ones;
      }
    }

    // Generate all possibilities.
    std::unordered_map<unsigned, long> curr{{0, 1}}, next{curr};
    for (int i{}; i < 31; ++i, curr = next) {
      if (!freqs[i]) {
        continue;
      }
      for (auto [factors_mask, freq] : curr) {
        if (factors_mask & factors_[i]) {
          continue;
        }
        auto mask{factors_mask | factors_[i]};
        next[mask] = (next[mask] + (freqs[i] * freq)) % MOD;
      }
      curr = next;
    }

    // Get count of all subsets except ones.
    long res{};
    for (auto [factors_mask, freq] : curr) {
      if (factors_mask) {
        res = (res + freq) % MOD;
      }
    }

    // Get count of subsets of only ones.
    long ones_subsets{1};
    while (ones--) {
      ones_subsets = (ones_subsets << 1) % MOD;
    }

    return ((res * ones_subsets) + (ones_subsets - 1)) % MOD;
  }
};
