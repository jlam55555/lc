// Push onto input stack. Pop from output stack.
// Pops from output stack are in queue order.
//
// If output stack is empty, read all entries
// from input stack into the output stack.

// In other words, in.top() will be the latest pushed element.
// in.top+1() will be the second to last pushed element.
// so on for in array.
//
// On the other hand, out.top() will be the first pushed element.
// out.top+1() will be the second pushed element.
//
// If out is empty, then all of the elements lie in in.
// Then the oldest element is at the bottom of s1, and the newest
// element is at s1.top(). By popping all of the elements from
// s1 into s2, then we reverse this and maintain the invariant
// from before.
//
// Another part of the invariant is that all of the values in
// s2 are older than values in s1.
class MyQueue {
public:
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    CleanupOutputStack();
    auto x{s2.top()};
    s2.pop();
    return x;
  }

  int peek() {
    CleanupOutputStack();
    return s2.top();
  }

  bool empty() { return s1.empty() && s2.empty(); }

private:
  void CleanupOutputStack() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
  }

  std::stack<int> s1{}, s2{};
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
