class Solution {
public:
  bool isAnagram(const string_view s, const string_view t) {
    unsigned char_hist[26]{0};
    if (s.length() != t.length()) {
      return false;
    }
    for (auto i{0}; i < s.length(); ++i) {
      ++char_hist[s[i] - 'a'];
      --char_hist[t[i] - 'a'];
    }
    for (auto i{0}; i < 26; ++i) {
      if (char_hist[i]) {
        return false;
      }
    }
    return true;
  }
};
