class Solution {
public:
  bool IsVowel(char c) {
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
    }
    return false;
  }

  int vowelStrings(vector<string> &words, int left, int right) {
    int res{};
    for (int i{left}; i <= right; ++i) {
      res += IsVowel(words[i].front()) && IsVowel(words[i].back());
    }
    return res;
  }
};
