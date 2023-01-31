class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    std::stringstream e{expression};
    std::vector<int> ns;
    std::vector<char> ops;

    // Parse input.
    int n;
    char op;
    e >> n;
    ns.push_back(n);
    while (e >> op >> n) {
      ns.push_back(n);
      ops.push_back(op);
    }

    // Set up base case.
    n = ns.size();
    std::vector<std::vector<std::vector<int>>> dp(
        n, std::vector<std::vector<int>>(n + 1));
    for (int i{}; i < n; ++i) {
      dp[i][1].push_back(ns[i]);
    }

    // Do DP. This can also be done recursively.
    for (int k{2}; k <= n; ++k) {
      for (int start{0}; start <= n - k; ++start) {
        for (int split{1}; split < k; ++split) {
          auto l = dp[start][split];
          auto r = dp[start + split][k - split];
          for (auto lit : l) {
            for (auto rit : r) {
              int res;
              switch (ops[start + split - 1]) {
              case '+':
                res = lit + rit;
                break;
              case '-':
                res = lit - rit;
                break;
              case '*':
                res = lit * rit;
                break;
              default:
                throw logic_error{"shouldn't happen"};
              }
              dp[start][k].push_back(res);
            }
          }
        }
      }
    }

    return dp[0][n];
  }
};
