class Solution {
public:
  int firstUniqChar(string s) {
    int hist[26]{};
    for (auto c : s) {
      ++hist[c - 'a'];
    }
    for (auto i{0}; i < s.length(); ++i) {
      if (hist[s[i] - 'a'] < 2) {
        return i;
      }
    }
    return -1;
  }
};
