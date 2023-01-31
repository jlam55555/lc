typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
  void dfs(vvi &res, vi &stk, vi &nums, int i) {
    if (i == nums.size()) {
      res.push_back(stk);
    }

    // We can actually do away with the stack and simply
    // swap elements in place. But (I believe) this is a
    // more general solution.
    for (int j = i; j < nums.size(); ++j) {
      swap(nums[i], nums[j]);
      stk.push_back(nums[i]);
      dfs(res, stk, nums, i + 1);
      stk.pop_back();
      swap(nums[i], nums[j]);
    }
  }

  vvi permute(vi &nums) {
    vvi res{};
    vi stk{};
    dfs(res, stk, nums, 0);
    return res;
  }
};
