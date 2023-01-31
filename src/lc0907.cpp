class Solution {
public:
  int sumSubarrayMins(::vector<int> &A) {
    int len = A.size(), i, sum;
    ::stack<int>
        stk; // stack will store indices, and will be monotonically increasing
    vector<int> next_smaller(len, len), prev_smaller(len, -1);

    for (i = 0; i < len; ++i) {
      while (!stk.empty() && A[i] <= A[stk.top()]) {
        next_smaller[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }

    while (!stk.empty())
      stk.pop();
    for (i = len - 1; i >= 0; --i) {
      while (!stk.empty() && A[i] < A[stk.top()]) {
        prev_smaller[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }

    for (i = 0, sum = 0; i < len; ++i)
      sum = (sum + A[i] * (i - prev_smaller[i]) * (next_smaller[i] - i)) %
            1000000007;

    return sum;
  }
};
