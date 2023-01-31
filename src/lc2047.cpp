class Solution {
public:
  bool isLowercase(string &s) {
    for (char c : s) {
      if (isupper(c) || isdigit(c)) {
        return false;
      }
    }
    return true;
  }

  bool oneHyphen(string &s) {
    int numHyphens = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '-') {
        if (i == 0 || i == s.length() - 1 || !isalpha(s[i + 1])) {
          return false;
        }
        if (++numHyphens == 2) {
          return false;
        }
      }
    }
    return true;
  }

  bool onePunctuation(string &s) {
    for (int i = 0; i < s.length() - 1; ++i) {
      if (s[i] == ',' || s[i] == '!' || s[i] == '.') {
        return false;
      }
    }
    return true;
  }

  bool isValidWord(string s) {
    if (!s.length())
      return false;

    return isLowercase(s) && oneHyphen(s) && onePunctuation(s);
  }

  int countValidWords(string s) {
    int i, valid = 0;
    while ((i = s.find(' ')) != -1) {
      valid += isValidWord(s.substr(0, i));
      s = s.substr(i + 1);
    }

    return valid + isValidWord(s);
  }
};
