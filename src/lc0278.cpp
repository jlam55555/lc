// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    // Binary search.
    // Find first isBadVersion(i) for all j >= i
    long l{1}, r{long(n) + 1};
    while (l < r) {
      auto m{(l + r) >> 1};
      // m >= target
      if (isBadVersion(m)) {
        r = m;
      }
      // m < target
      else {
        l = m + 1;
      }
    }
    return l;
  }
};
