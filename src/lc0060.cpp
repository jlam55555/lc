class Solution {
  static constexpr const int fac[]{1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

public:
  // This is the same as @tso's solution.
  //
  // My original (lame) solution was simply
  // to call std::next_permutation() on the string
  // "12...n" k times. But of course, this is
  // much slower (but still passes Leetcode verification).
  string getPermutation(int n, int k) {
    std::string res;
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // k is 1-indexed, make it 0-indexed.
    --k;

    while (--n) {
      // Take the (k/dividend)th number of the
      // remaining nums.
      auto index{k / fac[n - 1]};
      res.push_back(nums[index] + '0');
      nums.erase(nums.begin() + index);

      // Recurse into the next number.
      k %= fac[n - 1];
    }

    // Choose the last number.
    res.push_back(nums[n] + '0');
    return res;
  }
};
