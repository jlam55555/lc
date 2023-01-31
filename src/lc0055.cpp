class Solution {
public:
  bool canJump(vector<int> &nums) {
    int furthest = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (i > furthest)
        return false;
      furthest = max(furthest, i + nums[i]);
      if (furthest >= nums.size() - 1)
        break;
    }

    return furthest >= nums.size() - 1;
  }
};
