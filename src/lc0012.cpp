// roman characters
const char symbs[4][2] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', ' '}};

class Solution {
public:
  void digitToRoman(int digit, int level, char *buf, int &pos) {
    int j;

    if (!digit)
      return;

    if (digit % 5 == 0) {
      buf[pos++] = symbs[level][1];
      return;
    }

    if (digit % 5 == 4) {
      buf[pos++] = symbs[level][0];
      buf[pos++] = digit > 5 ? symbs[level + 1][0] : symbs[level][1];
      return;
    }

    if (digit > 5)
      buf[pos++] = symbs[level][1];
    for (j = 0; j < digit % 5; ++j)
      buf[pos++] = symbs[level][0];
  }

  string intToRoman(int num) {
    string res{};
    int pos, i, pow10s[4] = {1, 10, 100, 1000};
    char buf[20];

    for (i = 3, pos = 0; i >= 0; --i) {
      digitToRoman(num / pow10s[i], i, buf, pos);
      num %= pow10s[i];
    }

    buf[pos] = '\0';

    return string{buf};
  }
};
