class Solution {
  class Node {
  public:
    bool found = false;
    list<int> adj;
  };

public:
  // returns 1 if new island, else 0
  // flood-fills the graph with dfs, based on Lee215's soln
  int floodFill(int i, vector<Node> &graph) {
    int alreadyFound;
    if (alreadyFound = graph[i].found)
      return 0;
    graph[i].found = true;

    for (int j : graph[i].adj)
      floodFill(j, graph);
    return !alreadyFound;
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    int len = connections.size(), islandCount = 0, i;
    vector<Node> graph(n);

    if (len < n - 1)
      return -1;

    // make the digraph
    for (int i = 0; i < len; ++i) {
      graph[connections[i][0]].adj.push_back(connections[i][1]);
      graph[connections[i][1]].adj.push_back(connections[i][0]);
    }

    // dfs flood fill
    for (islandCount = i = 0; i < n; ++i)
      islandCount += floodFill(i, graph);
    return islandCount - 1;
  }
};
