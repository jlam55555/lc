class Solution {
public:
  std::string MakePigLatinWord(const std::string_view word, int word_ind) {
    static bool vowel[26]{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
                          0, 0, 0, 1, 0, 0, 0, 0, 0, 1};
    std::string res;
    if (vowel[(word[0] | 0x20) - 'a']) {
      res += word;
    } else {
      res += word.substr(1);
      res.push_back(word[0]);
    }
    res.push_back('m');
    res.push_back('a');
    while (word_ind--) {
      res.push_back('a');
    }
    return res;
  }

  string toGoatLatin(const std::string_view sentence) {
    std::string res;
    auto word_count{0};
    for (auto i{0}; i < sentence.length();) {
      auto j{i + 1};
      while (j < sentence.length() && sentence[j] != ' ') {
        ++j;
      }

      res += MakePigLatinWord(sentence.substr(i, j - i), ++word_count);
      if (j < sentence.length()) {
        res.push_back(' ');
      }

      i = j + 1;
    }
    return res;
  }
};
