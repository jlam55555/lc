class Solution {
public:
  int countAsterisks(string s) {
    int bars{}, res{};
    for (char c : s) {
      if (c == '|') {
        ++bars;
      } else {
        res += c == '*' && !(bars & 1);
      }
    }
    return res;
  }
};
