int strStr(char *haystack, char *needle) {

  int i, j, nlen = strlen(needle), len = strlen(haystack) - nlen + 1;

  if (!nlen)
    return 0;

  for (i = 0; i < len; i++) {
    for (j = 0; j < nlen; j++)
      if (haystack[i + j] != needle[j])
        break;
    if (j == nlen)
      return i;
  }

  return -1;
}
