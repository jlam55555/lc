class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &stk,
           int sum, int target, int i) {

    if (sum > target || i == nums.size()) {
      if (sum == target) {
        res.push_back(stk);
      }
      return;
    }

    // keep pushing the current element until the target is reached
    int j;
    for (j = 0; sum <= target; ++j, sum += nums[i], stk.push_back(nums[i])) {
      dfs(res, nums, stk, sum, target, i + 1);
    }

    while (j-- > 0) {
      stk.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res{};
    vector<int> stk{};
    dfs(res, candidates, stk, 0, target, 0);

    return res;
  }
};
