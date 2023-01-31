class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) : k_{k} {
    for (auto i : nums) {
      add(i);
    }
  }

  int add(int val) {
    bs_.push(val);
    if (bs_.size() > k_)
      bs_.pop();
    return bs_.top();
  }

private:
  const int k_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> bs_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
