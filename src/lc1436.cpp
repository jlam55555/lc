class Solution {
public:
  string destCity(vector<vector<string>> &paths) {
    std::unordered_map<std::string, bool> out;
    for (const auto &edge : paths) {
      const auto &from = edge[0], to = edge[1];
      out[to];
      out[from] = true;
    }

    for (const auto &[city, has_out] : out) {
      if (!has_out) {
        return city;
      }
    }
    throw std::logic_error{"shouldn't happen"};
  }
};
