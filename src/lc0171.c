int titleToNumber(char *s) {

  int res = 0;

  do {
    res *= 26;
    res += *s - 'A' + 1;
  } while (*++s);

  return res;
}
