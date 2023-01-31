class Solution {
  bool ReadInt(std::string_view s, int &i, int &o) {
    while (i < s.length() && s[i] == ' ') {
      ++i;
    }

    if (i == s.length()) {
      return false;
    }

    int val{};
    while (i < s.length() && std::isdigit(s[i])) {
      val *= 10;
      val += s[i] - '0';
      ++i;
    }
    o = val;
    return true;
  }

  bool ReadOp(std::string_view s, int &i, char &op) {
    while (i < s.length() && s[i] == ' ') {
      ++i;
    }
    if (i == s.length()) {
      return false;
    }
    op = s[i++];
    return true;
  }

  void Simplify3(int &o1, char op1, int o2) {
    switch (op1) {
    case '+':
      o1 += o2;
      break;
    case '-':
      o1 -= o2;
      break;
    case '*':
      o1 *= o2;
      break;
    case '/':
      o1 /= o2;
      break;
    }
  }

  int Precedence(char op) {
    switch (op) {
    case '+':
    case '-':
      return 0;
    case '*':
    case '/':
      return 1;
    }
    throw logic_error{"shouldn't happen"};
  }

  void Simplify5(int &o1, char &op1, int &o2, char op2, int o3) {
    // Simplify left.
    if (Precedence(op1) >= Precedence(op2)) {
      Simplify3(o1, op1, o2);
      op1 = op2;
      o2 = o3;
    }
    // Simplify right.
    else {
      Simplify3(o2, op2, o3);
    }
  }

public:
  // Very simple parser knowing that there are only two
  // precedence levels. If there were any more, we may need
  // a full operator-precedence parser.
  int calculate(string s) {
    // Tokenize.
    int res{}, i{};
    int o1, o2, o3;
    char op1, op2;

    // Get initial startup. Cleanup if not full.
    ReadInt(s, i, o1);
    if (!ReadOp(s, i, op1) || !ReadInt(s, i, o2)) {
      return o1;
    }
    if (!ReadOp(s, i, op2) || !ReadInt(s, i, o3)) {
      Simplify3(o1, op1, o2);
      return o1;
    }

    // Main loop.
    do {
      Simplify5(o1, op1, o2, op2, o3);
    } while (ReadOp(s, i, op2) && ReadInt(s, i, o3));

    // Cleaning up.
    Simplify3(o1, op1, o2);
    return o1;
  }
};
