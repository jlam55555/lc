class Solution {
public:
  string reverseWords(string s) {
    // Word in [i,j).
    for (auto i{0}; i < s.length(); ++i) {
      auto j{i + 1};
      while (j < s.length() && s[j] != ' ') {
        ++j;
      }
      // At this point, i is at the beginning of a word, j is at a space or the
      // end of a word.
      std::reverse(s.begin() + i, s.begin() + j);
      i = j;
    }
    return s;
  }
};
