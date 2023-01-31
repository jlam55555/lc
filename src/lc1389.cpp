class Solution {
public:
  vector<int> createTargetArray(vector<int> &nums, vector<int> &index) {
    int l(nums.size());
    std::list<int> res;

    for (auto i{0}; i < l; ++i) {
      res.insert(std::next(res.begin(), index[i]), nums[i]);
    }

    return std::vector<int>(res.begin(), res.end());
  }
};
