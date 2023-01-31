class Solution {
public:
  vector<int> bfs(vector<vector<int>> &edges, int n) {
    vector<vector<int>> adj(n);

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    vector<int> distances(n, INT_MAX);
    queue<int> q;
    distances[0] = 0;

    q.push(0);

    while (!q.empty()) {
      int next = q.front();
      q.pop();

      for (auto i : adj[next]) {
        if (distances[i] == INT_MAX) {
          distances[i] = distances[next] + 1;
          q.push(i);
        }
      }
    }

    return distances;
  }

  int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {

    int n = patience.size();
    auto distances = bfs(edges, n);
    int maxTime = INT_MIN;

    for (int i = 1; i < n; ++i) {
      maxTime =
          max(maxTime, ((2 * distances[i] - 1) / patience[i]) * patience[i] +
                           (2 * distances[i]));
    }

    return maxTime + 1;
  }
};
