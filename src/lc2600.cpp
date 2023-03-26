class Solution {
public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    // Take all the ones we can.
    auto res{std::min(numOnes, k)};
    k -= res;

    // Take all the zeros we can.
    k -= std::min(numZeros, k);

    // Take remaining negative ones.
    return res - k;
  }
};
