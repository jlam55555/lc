class Solution {
public:
  bool isValid(string s) {

    int len, i;
    char c;

    stack<char> parens;

    for (len = s.length(), i = 0; i < len; i++) {
      switch (c = s.at(i)) {
      case '(':
      case '{':
      case '[':
        parens.push(c);
        break;
      case ')':
        if (parens.empty() || parens.top() != '(')
          return false;
        parens.pop();
        break;
      case '}':
        if (parens.empty() || parens.top() != '{')
          return false;
        parens.pop();
        break;
      case ']':
        if (parens.empty() || parens.top() != '[')
          return false;
        parens.pop();
        break;
      }
    }

    return parens.empty();
  }
};
