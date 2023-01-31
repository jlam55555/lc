class Solution {
public:
  string largestOddNumber(string num) {
    int n = INT_MIN;
    n = max(n, (int)num.rfind('1'));
    n = max(n, (int)num.rfind('3'));
    n = max(n, (int)num.rfind('5'));
    n = max(n, (int)num.rfind('7'));
    n = max(n, (int)num.rfind('9'));

    if (n == -1) {
      return "";
    }

    return num.substr(0, n + 1);
  }
};
