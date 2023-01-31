class MinStack {
  std::vector<int> stk_;
  std::stack<int> mins_;

public:
  MinStack() {}

  void push(int val) {
    if (mins_.empty() || val <= stk_[mins_.top()]) {
      mins_.push(stk_.size());
    }
    stk_.push_back(val);
  }

  void pop() {
    stk_.pop_back();
    if (mins_.top() == stk_.size()) {
      mins_.pop();
    }
  }

  int top() { return stk_.back(); }

  int getMin() { return stk_[mins_.top()]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
