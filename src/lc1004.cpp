class Solution {
public:
  int longestOnes(::vector<int> &A, int K) {
    int left, right, currentSum, len, maxWinSize = -1;

    // criteria: right - left + 1 <= currentSum + K

    // maintain a window that fulfills the criteria
    for (left = right = currentSum = 0, len = A.size(); right < len; ++right) {
      currentSum += A[right];

      // if condition is broken, keep moving the left pointer right until
      // it is satisfied
      while (left < right && right - left + 1 > currentSum + K)
        currentSum -= A[left++];

      if (right - left + 1 <= currentSum + K)
        maxWinSize = ::max(maxWinSize, right - left);
    }

    return maxWinSize + 1;
  }
};
