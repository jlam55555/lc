class Solution {
public:
  // Fixed-size window approach.
  int minimumRecolors(string blocks, int k) {
    // Construct initial window.
    int bs{};
    for (int i{}; i < k - 1; ++i) {
      bs += blocks[i] == 'B';
    }
    int res{INT_MAX};
    // Slide window. Window lies in range [i, i+k).
    for (int i{}, n(blocks.length()); i <= n - k; ++i) {
      bs += blocks[i + k - 1] == 'B';
      res = std::min(res, k - bs);
      bs -= blocks[i] == 'B';
    }
    return res;
  }
};
