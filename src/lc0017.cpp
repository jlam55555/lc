vector<char> num_map[] = {
    {},
    {},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'},
};

class Solution {
public:
  void dfs(vector<string> &res, vector<char> &stk, string &digits, int i) {
    if (i == digits.length()) {
      res.push_back(string(stk.begin(), stk.end()));
      return;
    }

    for (auto ch : num_map[digits[i] - '0']) {
      stk.push_back(ch);
      dfs(res, stk, digits, i + 1);
      stk.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> res{};
    vector<char> stk{};

    if (!digits.length()) {
      return res;
    }

    dfs(res, stk, digits, 0);

    return res;
  }
};
