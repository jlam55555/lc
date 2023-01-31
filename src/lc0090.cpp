typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
  void subsets_rec(vvi &res, vi &stk, vi &nums, vi &counts, int i) {
    if (i == nums.size()) {
      res.push_back(stk);
      return;
    }

    // include element from 0 to counts[i] times
    for (int j = 0; j <= counts[i]; ++j) {
      subsets_rec(res, stk, nums, counts, i + 1);
      stk.push_back(nums[i]);
    }

    for (int j = 0; j <= counts[i]; ++j) {
      stk.pop_back();
    }
  }

  vvi subsetsWithDup(vi &nums) {
    vvi res{};
    vi stk{}, numsUniq{}, counts{};
    int curPos = -1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (i && nums[i] == nums[i - 1]) {
        ++counts[curPos];
      } else {
        numsUniq.push_back(nums[i]);
        counts.push_back(1);
        ++curPos;
      }
    }

    subsets_rec(res, stk, numsUniq, counts, 0);
    return res;
  }
};
