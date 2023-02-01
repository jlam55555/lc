class NumArray {
  // Segment tree implementation.
  // This is a very basic node-based tree implementation.
  // There is also a more efficient array-based implementation.
  //
  // There is also a binary indexed tree (Fenwick tree)
  // solution for this.
  struct SegmentNode {
    int val;
    int l;
    int r;
    SegmentNode *left;
    SegmentNode *right;

    void Update(int index, int new_val) {
      if (l == index && r - 1 == index) {
        val = new_val;
        return;
      }
      int m{(l + r) >> 1};
      if (index < m) {
        left->Update(index, new_val);
      } else {
        right->Update(index, new_val);
      }
      val = left->val + right->val;
    }

    int SumRange(int range_l, int range_r) {
      if (range_r <= l || range_l >= r) {
        return 0;
      }
      if (range_l == l && range_r == r) {
        return val;
      }
      int m{(l + r) >> 1};
      int sum{};
      if (range_l < m) {
        sum += left->SumRange(range_l, std::min(range_r, m));
      }
      if (range_r >= m) {
        sum += right->SumRange(std::max(m, range_l), range_r);
      }
      return sum;
    }
  };

  SegmentNode *BuildTree(int l, int r) {
    if (r == l) {
      // Shouldn't happen.
      throw logic_error{"shouldn't happen"};
    }
    if (r - l == 1) {
      return new SegmentNode{bs_[l], l, r, nullptr, nullptr};
    }
    auto m{(l + r) >> 1};
    auto left = BuildTree(l, m);
    auto right = BuildTree(m, r);
    return new SegmentNode{left->val + right->val, l, r, left, right};
  }

  std::vector<int> bs_;
  SegmentNode *root_;

public:
  NumArray(const std::vector<int> &nums)
      : bs_(std::move(nums)), root_{BuildTree(0, nums.size())} {}

  void update(int index, int val) { root_->Update(index, val); }

  int sumRange(int left, int right) { return root_->SumRange(left, right + 1); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
