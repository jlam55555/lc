class Solution {
public:
  // For each b in nums, we count the number of triplets
  // (a, b, c) where a < b, b < c. To get this, we count
  // (number of elems < b) * (frequency of b) * (number of elems > b)
  // and aggregate the sums for all values of b.
  //
  // Inspired by @votrubac's solution.
  int unequalTriplets(vector<int> &nums) {
    std::unordered_map<int, int> freqs;
    for (int i : nums) {
      ++freqs[i];
    }
    int res{}, left{}, right(nums.size());
    for (auto [unused, freq] : freqs) {
      right -= freq;
      res += left * freq * right;
      left += freq;
    }
    return res;
  }
};
