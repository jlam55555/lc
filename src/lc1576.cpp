class Solution {
public:
  string modifyString(string s) {

    int left = -1, right = -1, len = s.length();

    for (int i = 0; i < len; ++i) {
      if (s[i] == '?') {
        if (left == -1) {
          left = i;
        }
        right = i;

        // reached end of question mark substring; do transformation
        if (i == len - 1 || s[i + 1] != '?') {
          char prev = left ? s[left - 1] : 0;
          char next = i == len - 1 ? 0 : s[i + 1];

          // if one character
          if (left == right) {
            s[left] = (prev != 'a' && next != 'a')
                          ? 'a'
                          : ((prev != 'b' && next != 'b') ? 'b' : 'c');
            left = -1;
            continue;
          }

          // if multiple characters
          // set left and right most
          s[left] = (prev != 'a') ? 'a' : 'b';
          s[right] = (next != 'c') ? 'c' : 'd';

          // fill in middle letters
          for (int j = left + 1; j < right; ++j) {
            s[j] = j % 2 ? 'e' : 'f';
          }

          left = -1;
        }
      }
    }

    return s;
  }
};
