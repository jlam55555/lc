class Solution {
public:
  // General idea: we are removing every other item from an array,
  // then removing every other item from the modified array, and so
  // on. Relative to the original array, we are first removing every
  // other item, then every fourth item, then every eighth item, etc.
  // Since these are powers of two, we can use the binary form to aid
  // us here. Removing every kth item where k=2^n is the same as
  // removing each item where i&1u<<n == b (where b=0 or b=1).
  // We find b by looking at the first or last element in the remaining
  // range.
  //
  // With each round, we find one more bit to exclude, and we mask
  // out half of the numbers. Then we update our left and right pointers
  // accordingly.
  //
  // This is an O(log^2(n)) time and O(1) space algorithm.
  int lastRemaining(int n) {
    int l, r, i, j;
    unsigned mask, bit;
    bool remove_from_left;
    std::vector<unsigned> masks;

    for (l = 1, r = n, i = 0, mask = 1u, remove_from_left = true; l < r;
         remove_from_left ^= 1, ++i, mask <<= 1) {
      // Find the bit to exclude.
      if (remove_from_left) {
        bit = l & mask;
        ++l;
      } else {
        bit = r & mask;
        --r;
      }
      masks.push_back(bit);

      // Fix up left and right pointers. Make sure
      // they don't match any of the excluded bits.
      bit = 1u;
      for (auto mask : masks) {
        if ((l & bit) == mask) {
          l += bit;
        }
        if ((r & bit) == mask) {
          r -= bit;
        }
        bit <<= 1;
      }
    }

    return l;
  }
};
