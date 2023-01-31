class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
    vector<vector<int>> adj(n);
    unordered_set<int> unseen{};

    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    for (int i = 0; i < n; ++i) {
      unseen.insert(i);
    }

    // bfs; probably easier to bfs this
    queue<int> q{};
    q.push(start);
    unseen.erase(start);
    while (!q.empty()) {
      int n = q.front();
      q.pop();

      if (n == end) {
        return true;
      }

      for (int next : adj[n]) {
        if (unseen.count(next)) {
          unseen.erase(next);
          q.push(next);
        }
      }
    }

    return false;
  }
};
