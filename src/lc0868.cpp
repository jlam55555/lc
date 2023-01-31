class Solution {
public:
  int binaryGap(int n) {
    // No two 1's: power of 2
    if (!(n & (n - 1))) {
      return 0;
    }

    auto max_dist{1};
    while (!(n & 1)) {
      n >>= 1;
    }

    while (n >>= 1) {
      // Find the next one.
      auto dist{1};
      while (!(n & 1)) {
        n >>= 1;
        ++dist;
      }
      max_dist = std::max(dist, max_dist);
    }

    return max_dist;
  }
};
