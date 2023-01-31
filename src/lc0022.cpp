class Solution {
public:
  void dfs(vector<string> &res, vector<char> &stk, int depth, int rem) {
    if (depth == 0 && rem == 0) {
      res.push_back(string(stk.begin(), stk.end()));
      return;
    }

    if (rem) {
      stk.push_back('(');
      dfs(res, stk, depth + 1, rem - 1);
      stk.pop_back();
    }

    if (depth) {
      stk.push_back(')');
      dfs(res, stk, depth - 1, rem);
      stk.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> res{};
    vector<char> stk{};

    dfs(res, stk, 0, n);

    return res;
  }
};
