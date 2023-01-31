// Invariant: popping from q_ will give the
// result in stack order. That means that
// q_.front() is the newest element, q_.front+1()
// is the next newest, q_.back() is the oldest element.
//
// To maintain this invariant, when we push, we need
// to make sure that the inserted element becomes
// q_.front(), and the next element becomes
// q_.front+1(), and so on. Basically, this means
// that we have to cycle q_, since the order remains
// the same.
//
//             q_
// push 1      [1]
// push 2      [1,2]
//             [2,1]
// push 3      [2,1,3]
//             [1,3,2]
//             [3,2,1]

class MyStack {
public:
  MyStack() {}

  void push(int x) {
    q_.push(x);
    auto n{q_.size()};
    while (--n) {
      q_.push(q_.front());
      q_.pop();
    }
  }

  int pop() {
    auto x{q_.front()};
    q_.pop();
    return x;
  }

  int top() { return q_.front(); }

  bool empty() { return q_.empty(); }

private:
  std::queue<int> q_{};
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
