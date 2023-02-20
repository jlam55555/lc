class Solution {
public:
  string firstPalindrome(vector<string> &words) {
    for (const auto &word : words) {
      for (int i{}, n(word.size()); i < n / 2; ++i) {
        if (word[i] != word[n - 1 - i]) {
          goto fail;
        }
      }
      return word;
    fail:;
    }
    return "";
  }
};
