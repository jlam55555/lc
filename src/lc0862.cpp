class Solution {
public:
  int shortestSubarray(vector<int> &A, int K) {
    int len = A.size(), *P = new int[len + 1]{0}, i, minWinSize = INT_MAX;
    ::deque<int> opty;

    // calculate running sum (prefix sums)
    for (i = 0; i < len; ++i)
      P[i + 1] = P[i] + A[i];

    for (i = 0; i <= len; ++i) {
      while (!opty.empty() && P[i] - P[opty.front()] >= K) {
        minWinSize = ::min(minWinSize, i - opty.front());
        opty.pop_front();
      }
      while (!opty.empty() && P[i] <= P[opty.back()])
        opty.pop_back();
      opty.push_back(i);
    }
    return minWinSize == INT_MAX ? -1 : minWinSize;
  }
};
