// Note the interesting constraint on this problem:
// Each node has *at most one* outgoing edge. This means that
// each node can be in at most one cycle. Thus we simply use
// Floyd's cycle-finding algorithm to determine the length of
// each cycle we detect.
class Solution {
public:
  int longestCycle(vector<int> &edges) {
    auto res{-1};
    for (int i{}, n(edges.size()), len; i < n; ++i) {
      // Floyd's cycle-finding algorithm.
      // If there is a cycle, then count its length.
      int slow{i}, fast{edges[i]};
      while (slow != fast) {
        // Reached the end.
        if (fast == -1 || edges[fast] == -1) {
          goto continue_;
        }
        slow = edges[slow];
        fast = edges[edges[fast]];
      }

      // Count the length of the cycle.
      len = 0;
      do {
        fast = edges[fast];
        ++len;
      } while (slow != fast);
      res = std::max(res, len);

    continue_:;

      // Mark each node as seen.
      for (int j{i}; edges[j] != -1;
           std::tie(j, edges[j]) = std::make_pair(edges[j], -1))
        ;
    }
    return res;
  }
};
