class Solution {
public:
  int countSegments(const std::string_view s) {
    // `i` represents the start of a segment.
    auto count{0};
    for (auto i{0}; i < s.length();) {
      while (i < s.length() && s[i] == ' ') {
        ++i;
      }
      auto j{i};
      while (j < s.length() && s[j] != ' ') {
        ++j;
      }
      // Either:
      // - i == j == s.length()
      // - i is not space, j is at a space or end of string.
      if (i < j) {
        ++count;
      }
      i = j;
    }
    return count;
  }
};
