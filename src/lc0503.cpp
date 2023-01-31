class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    ::stack<int> stk; // stores indices
    int len = nums.size(), i;
    vector<int> nextVals(len, -1);

    for (i = 0; i < len; ++i) {
      while (!stk.empty() && nums[stk.top()] < nums[i]) {
        nextVals[stk.top()] = nums[i];
        stk.pop();
      }
      stk.push(i);
    }

    for (i = 0; i < len; ++i) {
      while (!stk.empty() && nums[stk.top()] < nums[i]) {
        nextVals[stk.top()] = nums[i];
        stk.pop();
      }
    }

    return nextVals;
  }
};
