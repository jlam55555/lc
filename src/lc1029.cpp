typedef pair<int, int> pi;

class Solution {
public:
  struct myComp {
    // first element stores the value, the second stores the index
    bool operator()(const pi &a, const pi &b) { return a.first < b.first; }
  };

  int twoCitySchedCost(vector<vector<int>> &costs) {

    priority_queue<pi, vector<pi>, myComp> aCosts{};

    int n = costs.size();

    if (n % 2 != 0) {
      throw invalid_argument{"odd number of elements in costs"};
    }

    for (int i = 0; i < n; ++i) {
      aCosts.push({costs[i][1] - costs[i][0], i});
    }

    int i;
    int sum = 0;
    for (i = 0; i < n / 2; ++i) {
      auto p = aCosts.top();
      aCosts.pop();
      sum += costs[p.second][0];
    }

    for (; i < n; ++i) {
      auto p = aCosts.top();
      aCosts.pop();
      sum += costs[p.second][1];
    }

    return sum;
  }
};
