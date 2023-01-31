class Solution {
public:
  bool IsVowel(char c) {
    static bool char_map[26]{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
                             0, 0, 0, 1, 0, 0, 0, 0, 0, 1};
    auto ind{(c | 0x20) - 'a'};
    return ind >= 0 && ind < 26 && char_map[ind];
  }

  string reverseVowels(string s) {
    auto l{0}, r{int(s.length()) - 1};
    while (l < r) {
      // Find next l and r
      while (!IsVowel(s[l]) && l < r) {
        ++l;
      }
      while (!IsVowel(s[r]) && l < r) {
        --r;
      }
      if (l < r) {
        std::swap(s[l], s[r]);
      }
      ++l;
      --r;
    }
    return s;
  }
};
