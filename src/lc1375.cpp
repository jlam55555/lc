// A binary string is prefix-aligned if all numbers
// left of the split have been flipped and all numbers
// right of the split haven't been flipped.
//
// We can track this by keeping track of the largest
// digit we've seen so far and a cumulative sum.
// If sum(numbers) == max*(max+1)/2 (== 1 + 2 + ... max)
// then all numbers left of the max have been flipped
// (and none of the numbers right of the max have been
// flipped).
class Solution {
public:
  int numTimesAllBlue(vector<int> &flips) {
    int max{}, res{};
    // Slight overflow forces us to use at least unsigned.
    unsigned sum{};
    for (int i : flips) {
      max = std::max(max, i);
      res += (sum += i) == unsigned(max) * (max + 1) / 2;
    }
    return res;
  }
};
