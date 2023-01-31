class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &stk, vector<int> &cs, int cc,
           int t) {
    if (t < 0) {
      return;
    }
    if (!t) {
      res.push_back(stk);
    }

    for (int i = 0; i < cc; ++i) {
      // prevent duplication of any but the last number
      if (i < cc - 1 && cs[i] == cs[i + 1])
        continue;

      stk.push_back(cs[i]);
      dfs(res, stk, cs, i, t - cs[i]);
      stk.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res{};
    vector<int> stk{};

    sort(candidates.begin(), candidates.end());
    dfs(res, stk, candidates, candidates.size(), target);

    return res;
  }
};
