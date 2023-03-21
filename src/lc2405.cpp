// If we see a duplicate character, start the next
// substring.
class Solution {
public:
  int partitionString(string s) {
    int res{};
    for (int i{}, n(s.length()); i < n; ++res) {
      unsigned seen{};
      int j{i};
      while (j < n && !(seen & (1u << (s[j] - 'a')))) {
        seen |= 1u << (s[j++] - 'a');
      }
      i = j;
    }
    return res;
  }
};
