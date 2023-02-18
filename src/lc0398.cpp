class Solution {
  std::unordered_map<int, std::vector<int>> nums_;

public:
  Solution(vector<int> &nums) {
    for (int i{}; i < nums.size(); ++i) {
      nums_[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    return nums_[target][std::rand() % nums_[target].size()];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
