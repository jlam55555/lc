class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    bool broken[26]{};
    for (auto c : brokenLetters) {
      broken[c - 'a'] = 1;
    }
    int res{};
    for (int i{}, n(text.length()); i < n; ++i) {
      int j{i};
      bool valid_word{true};
      while (j < n && text[j] != ' ') {
        if (broken[text[j++] - 'a']) {
          valid_word = false;
        }
      }
      res += valid_word;
      i = j;
    }
    return res;
  }
};
