class Solution {
public:
  // Basically check if there's more than one time that
  // the array decreases between elements.
  bool check(vector<int> &nums) {
    bool decreased{};
    int n(nums.size());
    for (int i{}; i < n; ++i) {
      if (nums[i] < nums[(i + n - 1) % n]) {
        if (!decreased) {
          decreased = true;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
