// Not sure why this isn't an easy question.
// This follows a pattern very similar to many
// Leetcode easy questions.
class Solution {
public:
  int longestBeautifulSubstring(string word) {
    int res{};
    char vowels[]{'a', 'e', 'i', 'o', 'u', 0};
    for (int i{}, n(word.length()); i < n;) {
      // Find the start of the next "longest beautiful substring".
      if (word[i] != 'a') {
        ++i;
        continue;
      }

      // Found the beginning of a substring, iterate through it.
      int cur_vowel{}, j{i};
      while (j < n && (word[j] == vowels[cur_vowel] ||
                       word[j] == vowels[cur_vowel + 1])) {
        if (word[j] == vowels[cur_vowel + 1]) {
          ++cur_vowel;
        }
        ++j;
      }

      // Found a beautiful substring.
      // std::cout << cur_vowel << " " << word.substr(i, j-i) << std::endl;
      if (cur_vowel >= 4) {
        res = std::max(res, j - i);
      }
      i = j;
    }
    return res;
  }
};
