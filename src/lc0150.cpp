class Solution {
  ::unordered_map<char, int (*)(int, int)> opMap;

public:
  Solution() {
    opMap['+'] = [](int a, int b) { return a + b; };
    opMap['*'] = [](int a, int b) { return a * b; };
    opMap['-'] = [](int a, int b) { return a - b; };
    opMap['/'] = [](int a, int b) { return a / b; };
  }

  int evalRPN(vector<string> &tokens) {
    ::stack<int> operands;
    int op1, op2;

    for (string token : tokens)
      // operator
      if (token.length() == 1 && token[0] <= '/' && token[0] >= '*') {
        op1 = operands.top();
        operands.pop();
        op2 = operands.top();
        operands.pop();
        operands.push(opMap[token[0]](op2, op1));
      } else
        operands.push(::stoi(token));

    return operands.top();
  }
};
