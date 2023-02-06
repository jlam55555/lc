// Algorithm: if there is a letter that makes the string
// not-nice, then it cannot be part of the longest substring.
// So we split the string and try again. This is an
// O(n*log(n)) average-case divide-and-conquer algorithm.
//
// This algorithm wasn't immediately obvious to me (for
// an easy question); the brute force solution also is fine
// for such a small input size.
class Solution {
public:
  std::string_view Dfs(std::string_view s) {
    // Base case.
    if (s.empty()) {
      return s;
    }

    // Check which letters exist.
    bool exists['z' + 1]{};
    for (char c : s) {
      exists[c] = 1;
    }

    // Find letters that are not good, and use that to split
    // the array.
    for (int i{}; i < s.length(); ++i) {
      if (!exists[s[i] ^ 0x20]) {
        auto left = Dfs(s.substr(0, i));
        auto right = Dfs(s.substr(i + 1));
        return left.length() >= right.length() ? left : right;
      }
    }

    // Whole string is good.
    return s;
  }

  string longestNiceSubstring(string s) {
    return std::string{Dfs(std::string_view{s})};
  }
};
