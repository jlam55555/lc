// Removing a node splits the binary tree into three
// (possibly trivial) subtrees:
// - The parent, not including the current node and its children.
// - The left child.
// - The right child.
//
// It is fairly easy to compute all of these, assuming we know
// the size of each subtree.
class Solution {
  struct Node {
    int left{-1};
    int right{-1};
    int size{};
  };

public:
  int CountSubtree(std::vector<Node> &g, int i) {
    if (i == -1) {
      return 0;
    }

    return g[i].size =
               1 + CountSubtree(g, g[i].left) + CountSubtree(g, g[i].right);
  }

  int countHighestScoreNodes(vector<int> &parents) {
    int n(parents.size());

    // Transform tree into more usable form.
    std::vector<Node> g(n);
    for (int i{1}; i < n; ++i) {
      (g[parents[i]].left != -1 ? g[parents[i]].right : g[parents[i]].left) = i;
    }

    // Count size of each subtree.
    CountSubtree(g, 0);

    // Compute score for each node.
    long best_score{};
    int res{};
    for (int i{}; i < n; ++i) {
      auto sc1{i ? n - g[i].size : 1},
          sc2{g[i].left == -1 ? 1 : g[g[i].left].size},
          sc3{g[i].right == -1 ? 1 : g[g[i].right].size};
      long score{long(sc1) * sc2 * sc3};
      if (score == best_score) {
        ++res;
      } else if (score > best_score) {
        res = 1;
        best_score = score;
      }
    }
    return res;
  }
};
