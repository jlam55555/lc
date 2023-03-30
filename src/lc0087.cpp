// Recursively try to divide the string into two
// contiguous parts.
//
// Substrings can only be up to 30 letters each,
// so we don't have to be too worried about being
// clever if the algorithm is okay.
class Solution {
  using Freqs = std::array<int, 26>;

  // Memoization, otherwise we get TLE.
  std::unordered_map<std::string, bool> seen_;

public:
  bool isScramble(std::string_view s1, std::string_view s2) {
    std::string key{s1};
    key += s2;

    if (seen_.count(key)) {
      return seen_[key];
    }

    if (s1 == s2) {
      return true;
    }

    int n(s1.length());
    if (n == 1) {
      return false;
    }

    Freqs s1_beg{}, s1_end{}, s2_beg{};
    for (int i{}; i < n - 1; ++i) {
      ++s1_beg[s1[i] - 'a'];
      ++s1_end[s1[n - 1 - i] - 'a'];
      ++s2_beg[s2[i] - 'a'];

      // Found a valid split. The prefix of s2 is
      // a scrambled version of the beginning or
      // end part of s1.
      if (s2_beg == s1_beg) {
        if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) &&
            isScramble(s1.substr(i + 1), s2.substr(i + 1))) {
          return seen_[key] = true;
        }
      }
      if (s2_beg == s1_end) {
        if (isScramble(s1.substr(0, n - i - 1), s2.substr(i + 1)) &&
            isScramble(s1.substr(n - i - 1), s2.substr(0, i + 1))) {
          return seen_[key] = true;
        }
      }
    }

    return seen_[key] = false;
  }
};
