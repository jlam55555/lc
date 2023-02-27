class Solution {
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                        vector<vector<int>> &items2) {
    std::unordered_map<int, int> items;
    for (const auto &item : items1) {
      items[item[0]] += item[1];
    }
    for (const auto &item : items2) {
      items[item[0]] += item[1];
    }
    std::vector<std::vector<int>> res;
    for (const auto &[value, item] : items) {
      res.push_back({value, item});
    }
    std::sort(res.begin(), res.end());
    return res;
  }
};
