// Need pairs of non-equal elements, or pairs of equal elements.
// If there is a leftover element of two repeated letters, we can
// also use this in the center.
class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    std::unordered_map<std::string, int> seen;
    for (const auto &word : words) {
      ++seen[word];
    }
    int res{};
    bool extra_two_letter{};
    for (const auto [word, count] : seen) {
      if (word[0] > word[1]) {
        continue;
      }
      if (word[0] == word[1]) {
        res += count / 2 * 4;
        extra_two_letter |= count & 1;
      } else if (auto it{seen.find(std::string{word[1], word[0]})};
                 it != seen.end()) {
        res += std::min(count, it->second) * 4;
      }
    }
    return res + extra_two_letter * 2;
  }
};
