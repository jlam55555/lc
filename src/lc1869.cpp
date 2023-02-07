class Solution {
public:
  bool checkZeroOnes(string s) {
    int longest_ones{}, longest_zeros{};
    for (int i{}; i < s.length();) {
      int j{i + 1};
      while (j < s.length() && s[j] == s[i]) {
        ++j;
      }
      if (s[i] == '0') {
        longest_zeros = std::max(longest_zeros, j - i);
      } else {
        longest_ones = std::max(longest_ones, j - i);
      }
      i = j;
    }
    return longest_ones > longest_zeros;
  }
};
