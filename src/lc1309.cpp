class Solution {
public:
  string freqAlphabets(::string s) {
    int i, j;
    for (i = j = s.length() - 1; i >= 0;)
      s[j--] =
          s[i] == '#' ? s[--i] + 10 * (s[(--i)--] - '0') + 48 : s[i--] + 48;

    return s.substr(j + 1);
  }
};
