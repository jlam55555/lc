class Solution {
public:
  vector<int> targetIndices(vector<int> &nums, int target) {
    // count how many, how many under
    int match = 0, under = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < target) {
        ++under;
      } else if (nums[i] == target) {
        ++match;
      }
    }

    vector<int> res{};
    for (int i = 0; i < match; ++i) {
      res.push_back(under + i);
    }
    return res;
  }
};
