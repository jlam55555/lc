class Solution {
public:
  vector<string> cellsInRange(string s) {
    auto c1{s[0]}, r1{s[1]}, c2{s[3]}, r2{s[4]};
    std::vector<std::string> res;
    for (; c1 <= c2; ++c1) {
      for (auto r{r1}; r <= r2; ++r) {
        res.emplace_back(std::string{c1, r});
      }
    }
    return res;
  }
};
