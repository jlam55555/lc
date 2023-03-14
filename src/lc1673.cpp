// Rephrasing the question: find the lexicographically-smallest
// subsequence of length k.
//
// We can use a monotonic stack. If the current number is smaller
// than the previous number, then we can pop the stack.
// The only constraint is that we need to have enough numbers
// following this number so that the stack has k elements by the end.
// This solution is borrowed from @lee215; I initially wrote a solution
// using a deque window rather than a stack. It works fairly similarly,
// but the memory  access pattern for deques/queues is worse than for
// stacks/vectors.
class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    std::vector<int> stk;
    for (int i{}, n(nums.size()); i < n; ++i) {
      while (!stk.empty() && nums[i] < stk.back() && stk.size() + n - i > k) {
        stk.pop_back();
      }
      stk.push_back(nums[i]);

      // Prevent stack from growing larger than it needs to.
      if (stk.size() > k) {
        stk.pop_back();
      }
    }
    return stk;
  }

  // Initial solution using a deque.
  //
  // Intuition:
  // 1. Find i_1 = argmin(0, n-k).
  // 2. Find i_2 = argmin(i_1, n-k+1).
  // ...
  // k. Find i_k = argmin(i_{k-1}, n).
  //
  // We evict numbers that are too old (from the front)
  // or which are larger than the current element (from the back).
  // The element at the front after these evictions is the smallest
  // element in the specified range.
  vector<int> mostCompetitive_deque(vector<int> &nums, int k) {
    std::deque<int> d;
    std::vector<int> res;
    int i{}, n(nums.size());

    for (int i{}; i < n; ++i) {
      while (!d.empty() && nums[i] < d.back()) {
        d.pop_back();
      }
      d.push_back(nums[i]);

      if (i >= n - k) {
        res.push_back(d.front());
        d.pop_front();
      }
    }

    return res;
  }
};
