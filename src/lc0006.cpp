class Solution {
public:
  string convert(string s, int nr) {
    int sl = s.length(), i = 0;
    char buf[sl + 1];

    if (nr < 2)
      return s;

    for (int c = 0; c < sl; c += 2 * (nr - 1)) {
      buf[i++] = s[c];
    }
    for (int r = 1; r < nr - 1; r++) {
      for (int c = 0;; c += 2 * (nr - 1)) {
        if (c + r < sl) {
          buf[i++] = s[c + r];
        }
        if (c + 2 * (nr - 1) - r < sl) {
          buf[i++] = s[c + 2 * (nr - 1) - r];
        }
        if (c + r >= sl || c + 2 * (nr - 1) - r >= sl)
          break;
      }
    }
    for (int c = nr - 1; c < sl; c += 2 * (nr - 1)) {
      buf[i++] = s[c];
    }

    buf[sl] = 0;

    return string(buf);
  }
};
