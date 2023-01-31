class Solution {
public:
  int jump(vector<int> &nums) {
    int current_steps = 0, current_max = 0, next_max = INT_MIN;

    if (nums.size() == 1) {
      return 0;
    }

    for (int i = 0; i < nums.size(); ++i) {
      next_max = max(next_max, i + nums[i]);

      // optimization: end early
      if (next_max >= nums.size() - 1) {
        return current_steps + 1;
      }

      if (i == current_max) {
        ++current_steps;
        current_max = next_max;
      }
    }

    throw logic_error{"logic error"};
  }
};
