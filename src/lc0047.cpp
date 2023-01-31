typedef vector<int> vi;
typedef list<int> li;
typedef vector<vi> vvi;

class Solution {
public:
  void dfs(vvi &res, vi &stk, li nums) {
    if (nums.empty()) {
      res.push_back(stk);
      return;
    }

    int prev = INT_MIN;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      if (*it == prev) {
        continue;
      }
      prev = *it;

      stk.push_back(*it);
      auto next = nums.erase(it);

      dfs(res, stk, nums);

      stk.pop_back();
      it = nums.insert(next, prev);
    }
  }

  vvi permuteUnique(vi &nums) {
    vvi res{};
    vi stk{};
    sort(nums.begin(), nums.end());
    li nums2(nums.begin(), nums.end());
    dfs(res, stk, nums2);
    return res;
  }
};
