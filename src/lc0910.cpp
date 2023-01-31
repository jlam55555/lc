class Solution {
public:
  int smallestRangeII(vector<int> &A, int K) {

    sort(A.begin(), A.end());

    // assume no split
    int range = A[A.size() - 1] - A[0];

    // try to find the split; all numbers above the split go down, all numbers
    // below the split go up
    for (int i = 0; i < A.size() - 1; ++i) {
      // assume that i is the last number that goes up
      // then minimum in range would be min((smallest number that goes up) + K,
      // (smallest value that goes down) - K) and maximum in range would be
      // max((largest number that goes up) + K, (largest number that goes down)
      // - K)
      int low = min(A[0] + K, A[i + 1] - K);
      int high = max(A[i] + K, A[A.size() - 1] - K);

      range = min(range, high - low);
    }

    return range;
  }
};
