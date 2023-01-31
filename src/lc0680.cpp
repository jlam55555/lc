class Solution {
public:
  bool IsPalindromeRemoved(const std::string_view s, int removed) {
    auto l{s.length() - 1};
    // This can be optimized to just look at the remainder, but I'm lazy.
    for (auto i{0}, count{0}, j{int(l)}; count < l / 2; ++i, ++count, --j) {
      if (i == removed) {
        ++i;
      } else if (j == removed) {
        --j;
      }
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

  bool validPalindrome(const std::string_view s) {
    auto l{s.length()};
    for (auto i{0}; i < l / 2; ++i) {
      if (s[i] != s[l - 1 - i]) {
        return IsPalindromeRemoved(s, i) || IsPalindromeRemoved(s, l - 1 - i);
      }
    }
    return true;
  }
};
