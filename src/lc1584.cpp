class Solution {
public:
  // Prim's algorithm.
  //
  // Note that Prim's algorithm is better than Kruskal's algorithm
  // here since it is better for dense graphs. Intuitively, this is
  // because we have to consider all edges upfront in Kruskal's
  // algorithm, while we iteratively only consider relevant edges
  // in Prim's algorithm. See: https://stackoverflow.com/a/1195932
  int minCostConnectPoints(std::vector<std::vector<int>> &points) {
    int n(points.size());

    // Use bitset to check whether we've added a vertex or not.
    std::bitset<1000> seen;

    // Priority queue to maintain lowest-cost edges between seen
    // nodes and unseen nodes. An edge is represented by a
    // (weight, to) pair. (Note: the "from" node is not important
    // as we don't have to compute the MST, just its weight.)
    using Edge = std::pair<int, int>;
    std::priority_queue<Edge, std::vector<Edge>, std::greater<>> pq;
    pq.push({0, 0});

    // Recurse.
    int res{}, connected{};
    while (connected++ < n) {
      // Remove edges until we find one that points to a
      // node we haven't seen yet.
      int edge_weight, edge_to;
      do {
        std::tie(edge_weight, edge_to) = pq.top();
        pq.pop();
      } while (seen.test(edge_to));

      // Add node to seen nodes, add all its edges to the pq.
      seen.set(edge_to);
      res += edge_weight;
      for (int i{}; i < n; ++i) {
        if (!seen.test(i)) {
          pq.push({std::abs(points[edge_to][0] - points[i][0]) +
                       std::abs(points[edge_to][1] - points[i][1]),
                   i});
        }
      }
    }

    return res;
  }
};
