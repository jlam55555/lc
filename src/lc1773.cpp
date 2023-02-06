class Solution {
public:
  int countMatches(vector<vector<string>> &items, string rule_key,
                   string rule_value) {
    int rule_key_i = rule_key == "type" ? 0 : (rule_key == "color" ? 1 : 2),
        res{};
    for (const auto &item : items) {
      res += item[rule_key_i] == rule_value;
    }
    return res;
  }
};
