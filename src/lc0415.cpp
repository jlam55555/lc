class Solution {
public:
  string addStrings(string num1, string num2) {
    // to reduce edge cases, front-pad both num1 and num2
    // so that they both have a leading zero and are
    // of the same length
    int endLen = max(num1.length(), num2.length());
    num1 = string(endLen - num1.length(), '0') + num1;
    num2 = string(endLen - num2.length(), '0') + num2;

    string res{};
    int carry = 0;

    // half adder
    for (int i = endLen - 1; i >= 0; --i) {
      int d1 = num1[i] - '0', d2 = num2[i] - '0';
      int d3 = (d1 + d2 + carry) % 10;
      carry = (d1 + d2 + carry) >= 10;

      // build string in reverse
      res += d3 + '0';
    }

    if (carry) {
      res += '1';
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
