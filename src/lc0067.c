char *addBinary(char *a, char *b) {
  int lena = strlen(a), lenb = strlen(b), carry = 0, halfsum, digit, i,
      maxlen = lena > lenb ? lena : lenb;
  char *res = (char *)malloc(maxlen + 2), aval, bval;

  res[maxlen + 1] = '\0';

  for (i = 0; i < maxlen + 1; i++) {
    aval = i < lena ? a[lena - 1 - i] : '0';
    bval = i < lenb ? b[lenb - 1 - i] : '0';
    halfsum = (aval == '1') + (bval == '1') + carry;
    digit = halfsum & 0b1;
    carry = halfsum >> 1 & 0b1;
    res[maxlen - i] = digit + '0';
  }

  return res[0] == '0' ? res + 1 : res;
}
