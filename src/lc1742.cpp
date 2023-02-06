class Solution {
public:
  // Too lazy to do any math here, just simply compute the result.
  int countBalls(int low_limit, int high_limit) {
    std::unordered_map<int, int> freqs;
    int res{};
    for (int i{low_limit}; i <= high_limit; ++i) {
      int digit_sum{}, j{i};
      while (j) {
        digit_sum += j % 10;
        j /= 10;
      }
      res = std::max(res, ++freqs[digit_sum]);
    }
    return res;
  }
};
