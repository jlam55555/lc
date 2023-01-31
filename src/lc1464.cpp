class Solution {
public:
  int maxProduct(vector<int> &nums) {
    // Don't need to do a full sort, just need two largest numbers.
    // I'm just lazy.
    std::sort(nums.begin(), nums.end());
    return (nums.back() - 1) * (nums[nums.size() - 2] - 1);
  }
};
