// Find the longest word in the dictionary that is a subsequence
// of `s`. This is a very straightforward algorithm.
class Solution {
public:
  // Returns true if s1 is a subsequence of s2.
  // Copied from lc0522.cpp.
  bool IsSubsequence(std::string_view s1, std::string_view s2) {
    if (s1.length() > s2.length()) {
      return false;
    }
    for (int i{}, j{}, n1(s1.length()), n2(s2.length()); i < n1; ++i, ++j) {
      while (j < n2 && s1[i] != s2[j]) {
        ++j;
      }
      if (j == n2) {
        return false;
      }
    }
    return true;
  }

  string findLongestWord(string s, vector<string> &dictionary) {
    // ORDER BY length DESC, word ASC
    std::sort(dictionary.begin(), dictionary.end(),
              [](const auto &s1, const auto &s2) {
                if (s1.length() != s2.length()) {
                  return s1.length() > s2.length();
                }
                return s1 < s2;
              });

    // Check if subsequence.
    for (const auto &word : dictionary) {
      if (IsSubsequence(word, s)) {
        return word;
      }
    }

    // Didn't find a word that was a subsequence.
    return {};
  }
};
