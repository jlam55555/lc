class Node {
public:
  int found = false;
  int time = INT_MAX;
  list<pair<int, int>> out;
  list<pair<int, int>> in;
};

vector<Node> *g;
class Solution {
  struct NodeComparator : public less<int> {
    bool operator()(int &a, int &b) const {
      return (*g)[a].time >= (*g)[b].time;
    }
  };

public:
  int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    vector<Node> graph(N);
    int maxTime = 0, count = 0;
    g = &graph;

    // create graph
    for (int i = 0; i < times.size(); ++i)
      graph[times[i][0] - 1].out.push_back(
          pair<int, int>(times[i][1] - 1, times[i][2]));

    // set up the pq
    priority_queue<int, vector<int>, NodeComparator> pq;
    graph[K - 1].time = 0;
    pq.push(K - 1);

    while (!pq.empty()) {
      int curr = pq.top();
      pq.pop();

      // already parsed, continue
      if (graph[curr].found)
        continue;
      graph[curr].found = true;
      ++count;
      maxTime = max(maxTime, graph[curr].time);

      for (pair<int, int> edge : graph[curr].out)
        if (!graph[edge.first].found &&
            graph[curr].time + edge.second < graph[edge.first].time) {
          graph[edge.first].time = graph[curr].time + edge.second;
          pq.push(edge.first);
        }
    }

    return count == N ? maxTime : -1;
  }
};
