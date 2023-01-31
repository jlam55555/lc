class Solution {
public:
#define lskip                                                                  \
  while (l < r && nums[l] == nums[l + 1])                                      \
    ++l;                                                                       \
  ++l
#define rskip                                                                  \
  while (l < r && nums[r] == nums[r - 1])                                      \
    --r;                                                                       \
  --r

  typedef vector<vector<int>> vvi;
  typedef vector<int> vi;

  vvi threeSum(vi &nums) {
    vvi res{};
    int i, l, r, t; // index, left, right, target

    sort(nums.begin(), nums.end());

    // optimization: stop when i>0
    for (i = 0; i < (int)nums.size() - 2 && nums[i] <= 0; ++i) {
      // avoid duplicates: if we've already checked this first
      // number, don't repeat it
      if (!i || nums[i] != nums[i - 1]) {

        // standard bi-directional 2-sum sweep
        // invariant: l, r are on the outermost duplicate (if any)
        l = i + 1, r = nums.size() - 1, t = -nums[i];
        while (l < r) {
          if (nums[l] + nums[r] == t) {
            res.push_back({nums[i], nums[l], nums[r]});
            lskip;
            rskip;
          } else if (nums[l] + nums[r] < t) {
            lskip;
          } else {
            rskip;
          }
        }
      }
    }

    return res;
  }
};
