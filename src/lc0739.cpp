class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &T) {
    // stack will be in decreasing order
    ::stack<int> stk;
    int len = T.size(), i;
    ::vector<int> nextHotterDay(len, 0);

    for (i = 0; i < len; ++i) {
      while (!stk.empty() && T[i] > T[stk.top()]) {
        nextHotterDay[stk.top()] = i - stk.top();
        stk.pop();
      }
      stk.push(i);
    }

    return nextHotterDay;
  }
};
