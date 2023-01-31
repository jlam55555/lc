class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    items.push_back({INT_MIN, 0});

    sort(items.begin(), items.end());

    int prev = INT_MIN;
    for (int i = 0; i < items.size(); ++i) {
      items[i][1] = max(prev, items[i][1]);
      prev = items[i][1];
    }

    vector<int> res{};

    for (int q : queries) {
      auto it =
          upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX});

      // find first element smaller than the query
      while (it == items.end() || (*it)[0] > q) {
        --it;
      }

      if ((*it)[0] > q)
        res.push_back(0);
      else
        res.push_back((*it)[1]);
    }

    return res;
  }
};
