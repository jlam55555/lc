class Solution {
public:
  vector<int> decompressRLElist(vector<int> &nums) {
    std::vector<int> res;
    for (auto i{0}; i < nums.size(); i += 2) {
      for (auto j{nums[i]}; j; --j) {
        res.push_back(nums[i + 1]);
      }
    }
    return res;
  }
};
