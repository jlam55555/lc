bool isPalindrome(char *s) {
  int len = strlen(s);
  if (!len)
    return 1;

  int len2, i;
  char *c = s;

  for (i = 0; i < len; i++) {
    if (s[i] >= 'a')
      s[i] ^= 0b100000;
    if (s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z')
      *c++ = s[i];
  }
  len2 = c - s;

  for (i = 0; i < len2 / 2; i++)
    if (s[i] - s[len2 - 1 - i])
      return false;
  return true;
}
