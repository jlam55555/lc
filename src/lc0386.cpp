// Simple backtracking algorithm. This is very similar to
// lc0077.cpp.
class Solution {
public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> res;

    // Backtracking just like a stack.
    // cur_digit indicates the current
    // depth of `stk`. (Number of digits in `stk`).
    int cur_digit{1}, stk{0};

    // `flag` prevents us from wrapping around.
    // There are two cases when we have a 9
    // as the last digit: after increasing
    // the stack depth; or after incrementing `stk`
    // normally. We only want to backtrack upon reaching
    // a nine in the last position due to the second
    // condition.
    bool flag{};

    while (cur_digit) {
      // Reached a nine or too large, backtrack.
      if (stk % 10 == 9 && !flag || ++stk > n) {
        stk /= 10;
        --cur_digit;
        flag = false;
        continue;
      }

      // Number is good, continue and increase stack depth.
      res.push_back(stk);
      stk = stk * 10 - 1;
      ++cur_digit;
      flag = true;
    }
    return res;
  }
};
