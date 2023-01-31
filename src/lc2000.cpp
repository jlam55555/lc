class Solution {
public:
  string reversePrefix(string word, char ch) {
    int i = 0;
    while (i < word.length() && word[i++] != ch)
      ;
    if (i == word.length() && word[i - 1] != ch)
      return word;

    // reverse string from [0,i)
    for (int j = 0; j < i / 2; ++j) {
      swap(word[j], word[i - j - 1]);
    }

    return word;
  }
};
