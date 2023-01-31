class Solution {
public:
  int longestValidParentheses(string s) {
    int maxLen = 0;

    stack<int> valid{};
    valid.push(-1);

    // if an element is part of a valid stack,
    // then it will be pushed onto the stack
    // when popping, we will see the last instance
    // of something of the same height on the valid
    // stack, and we can find the length of that
    // match easily
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        valid.push(i);
      } else {
        valid.pop();
        if (!valid.empty()) {
          maxLen = max(maxLen, i - valid.top());
        } else {
          valid.push(i);
        }
      }
    }

    return maxLen;
  }
};
