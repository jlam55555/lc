// Let z = number of zeros, o = number of ones.
//
// Easy to tell if it's impossible: abs(z-o) > 1
//
// Case breakdown:
// - If `z == o+1`, then zeros must be in even indices.
// - If `o == z+1`, then ones must be in even indices.
// - If `z == o`, then we need to count which digit
//   occurs more often in the even and odd indices
//   and choose accordingly.
class Solution {
public:
  int minSwaps(string s) {
    // Count zeros and ones.
    int z{}, o{}, n(s.length());
    for (char c : s) {
      ++(c == '1' ? o : z);
    }

    // Impossible.
    if (std::abs(z - o) > 1) {
      return -1;
    }

    // One digit has more than the other digit.
    if (z != o) {
      int res{};
      char even_ind_digit{z > o ? '0' : '1'};
      for (int i{}; i < n; ++i) {
        res += s[i] == even_ind_digit && i & 1;
      }
      return res;
    }

    // Same number of zeros and ones.
    // Count how many zeros are in the odd digits.
    // (This choice is arbitrary.)
    // Then `z - odd_zeros` is how many swaps it would
    // take to move all zeros to odd indices, and
    // `odd_zeros` is how many swaps it would take to
    // move all zeros to even indices.
    int odd_zeros{};
    for (int i{}; i < n; ++i) {
      odd_zeros += s[i] == '0' && i & 1;
    }
    return std::min(odd_zeros, z - odd_zeros);
  }
};
