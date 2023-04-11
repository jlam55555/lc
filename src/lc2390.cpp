// Very standard problem like lc1047.cpp
// (Remove all Adjacent Duplicates in String).
//
// Here I do it in place rather than using
// an extra stack/string object.
class Solution {
public:
  string removeStars(string s) {
    int i{};
    for (char c : s) {
      if (c == '*') {
        --i;
      } else {
        s[i++] = c;
      }
    }
    s.resize(i);
    return s;
  }
};
