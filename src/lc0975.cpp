class Solution {
public:
  int oddEvenJumps(::vector<int> &A) {
    int len = A.size();

    if (!len)
      return 0;

    ::vector<int> B(len);
    ::iota(B.begin(), B.end(), 0);
    ::stable_sort(B.begin(), B.end(),
                  [A](int a, int b) { return A[a] < A[b]; });

    ::vector<int> nextLargest(len, 0);
    ::stack<int> monoStack;
    for (int i = 0; i < len; ++i) {
      while (monoStack.size() && B[i] >= monoStack.top()) {
        nextLargest[monoStack.top()] = B[i];
        monoStack.pop();
      }
      monoStack.push(B[i]);
    }

    // clear stack, reuse for nextSmallest
    ::stable_sort(B.begin(), B.end(),
                  [A](int a, int b) { return A[a] > A[b]; });
    ::vector<int> nextSmallest(len, 0);
    while (monoStack.size())
      monoStack.pop();
    for (int i = 0; i < len; ++i) {
      while (monoStack.size() && B[i] >= monoStack.top()) {
        nextSmallest[monoStack.top()] = B[i];
        monoStack.pop();
      }
      monoStack.push(B[i]);
    }

    // dp works better backwards, can do it ine one pass
    ::vector<int[2]> cases(len);
    cases[len - 1][0] = 1;
    cases[len - 1][1] = 1;
    int goodCount = 1;
    for (int i = len - 2; i >= 0; --i) {
      cases[i][0] = cases[nextLargest[i]][1];
      cases[i][1] = cases[nextSmallest[i]][0];
      goodCount += cases[i][0];
    }

    return goodCount;
  }
};
