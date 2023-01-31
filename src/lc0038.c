char *countAndSay(int n) {

  int *seq = (int *)malloc(10000 * sizeof(int)),
      *tmp = (int *)malloc(10000 * sizeof(int)), *tmpP = tmp, len = 1, tmpLen,
      i, type, typeCount;

  *seq = 1;

  while (--n) {

    typeCount = 1;
    tmpLen = 0;

    for (i = 1; i <= len; i++) {
      if (i == len || seq[i] != seq[i - 1]) {
        type = seq[i - 1];

        *tmpP++ = typeCount;
        *tmpP++ = type;
        tmpLen += 2;

        typeCount = 1;
      } else {
        typeCount++;
      }
    }

    tmpP = tmp;
    memcpy(seq, tmp, tmpLen * sizeof(int));
    len = tmpLen;
  }

  char *res = (char *)malloc(len * sizeof(char)), *resP = res;
  while (len--) {
    *resP++ = *seq++ + '0';
  }

  return res;
}
