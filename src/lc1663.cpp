class Solution {
public:
  string getSmallestString(int n, int k) {
    char str[n + 1];
    str[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (k - 1 >= i + 26) {
        str[i] = 'z';
        k -= 26;
      } else {
        str[i] = k - i - 1 + 'a';
        k = i;
      }
    }
    return string(str);
  }
};
