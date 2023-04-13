class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    int n(pushed.size()), j{};
    std::stack<int> s;

    // Push all the elements, popping elements off when we encounter them.
    for (int i{}; i < n; s.push(pushed[i++])) {
      while (!s.empty() && s.top() == popped[j]) {
        s.pop();
        ++j;
      }
    }

    // Pop remaining elements. (Alternatively, see if the stack is
    // the reverse of the remaining elements.)
    while (!s.empty() && s.top() == popped[j]) {
      s.pop();
      ++j;
    }

    return s.empty();
  }
};
