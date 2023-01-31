class Solution {
public:
  int maximumDifference(vector<int> &nums) {
    int smallest = INT_MAX, largest_difference = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (i && nums[i] > smallest) {
        largest_difference = max(largest_difference, nums[i] - smallest);
      }
      smallest = min(smallest, nums[i]);
    }

    return largest_difference;
  }
};
