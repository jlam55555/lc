class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    // mark the presence of an element by negating the value of nums[i]
    for (int i : nums) {
      i = abs(i);
      if (nums[i - 1] > 0) {
        nums[i - 1] *= -1;
      }
    }

    vector<int> res{};
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        res.push_back(i + 1);
      }
    }

    return res;
  }
};
