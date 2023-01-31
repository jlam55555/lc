int lengthOfLastWord(char *s) {
  int len, i;
  for (len = strlen(s); len >= 1 && s[len - 1] == ' '; len--)
    ;
  for (i = len - 1; i != -1 && s[i] != ' '; i--)
    ;
  return len - i - 1;
}
