// At maximum there are about 4^9 = 2^18 different possible
// expressions (insert a +, -, *, or nothing between digits
// in a ten-digit number), which is a reasonable number
// to brute-force.
//
// In essence, this is a brute-force exponential search along
// with an (infix) 2-level expression evaluator. We group
// multiplied expressions into terms and add/subtract the terms
// to evaluate the result.
//
// I would like to solve this using dynamic programming, but
// it's difficult because each subproblem isn't self-contained;
// in other words, due to order of operations, the end value of
// a subproblem may be undefined without knowing the adjacent
// terms. So we simply brute force this without memoization.
// I was trying to think of a way to use DP in my solution
// but then looked at the editorial and realized that probably
// not reasonable to implement.
//
// For performance reasons, I try to avoid allocations wherever
// possible; the only real place for allocations is in the `res`
// vector. The `expr` variable works like a Java StringBuilder
// object or a `std::stack` and thus is fairly efficient.
class Solution {
public:
  // We use longs to avoid troubles with int overflow.
  void Dfs(std::string_view num, std::vector<std::string> &res,
           std::string &expr, int target, long acc_sum = 0, long cur_term = 1) {
    int n(num.length());
    auto leading_zeros{n > 1 && num.front() == '0'};

    // Treat the whole number as an operand
    // if no leading zeros.
    if (!leading_zeros) {
      long operand{};
      for (int j{}; j < n; ++j) {
        operand *= 10;
        operand += num[j] - '0';
        expr.push_back(num[j]);
      }
      auto val{acc_sum + cur_term * operand};
      if (val == target) {
        res.push_back(expr);
      }
      for (int j{}; j < n; ++j) {
        expr.pop_back();
      }
    }

    // Choose which digit to insert an operator before.
    // Forbid leading zeros.
    for (int i{1}, lim{leading_zeros ? 2 : n}; i < lim; ++i) {
      // std::stoi doesn't have a std::string_view implementation,
      // so write a simple implementation here.
      long operand{};
      for (int j{}; j < i; ++j) {
        operand *= 10;
        operand += num[j] - '0';
        expr.push_back(num[j]);
      }
      auto new_term{cur_term * operand};
      auto num_remainder{num.substr(i)};

      // Insert +.
      expr.push_back('+');
      Dfs(num_remainder, res, expr, target, acc_sum + new_term, 1);

      // Insert -.
      expr.back() = '-';
      Dfs(num_remainder, res, expr, target, acc_sum + new_term, -1);

      // Insert *.
      expr.back() = '*';
      Dfs(num_remainder, res, expr, target, acc_sum, new_term);

      // Remove operand and operator from the expression.
      expr.pop_back();
      for (int j{}; j < i; ++j) {
        expr.pop_back();
      }
    }
  }

  vector<string> addOperators(string num, int target) {
    std::vector<std::string> res;
    std::string expr;
    Dfs(num, res, expr, target);
    return res;
  }
};
