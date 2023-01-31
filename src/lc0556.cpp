class Solution {
public:
  int nextGreaterElement(int n) {
    string nAsString = ::to_string(n);
    int len = strlen(nAsString.c_str()), i, res;
    char *chars = new char[len + 1];
    strcpy(chars, nAsString.c_str());

    for (i = len - 2; i >= 0; --i) {
      if (chars[i] < chars[i + 1]) {
        // find min j that is greater than i;
        // already reverse sorted here (could use binary search here but meh)
        for (int j = len - 1;; --j) {
          if (chars[j] > chars[i]) {
            ::swap(chars[i], chars[j]);
            ::sort(chars + i + 1, chars + len);
            break;
          }
        }
        break;
      }
    }

    // i < 0 means it's already the largest it can be;
    // also make sure it doesn't exceed the bounds; 32-bit INT_MAX == 2147483647
    if (i < 0 || len == 10 && strcmp(chars, "2147483647") > 0) {
      return -1;
    }

    res = atoi(chars);
    delete[] chars;
    return res;
  }
};
