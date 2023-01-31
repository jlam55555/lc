class NumArray {
public:
  NumArray(vector<int> &nums) : cum_sums_(nums.size() + 1) {
    cum_sums_[0] = 0;
    for (auto i{0}; i < nums.size(); ++i) {
      cum_sums_[i + 1] = cum_sums_[i] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return cum_sums_[right + 1] - cum_sums_[left];
  }

private:
  std::vector<int> cum_sums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
