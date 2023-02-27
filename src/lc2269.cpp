class Solution {
public:
  int divisorSubstrings(int num, int k) {
    auto ns{std::to_string(num)};
    int res{};
    for (int i{}, n(ns.length()); i <= n - k; ++i) {
      auto val{std::stoi(ns.substr(i, k))};
      res += val && !(num % val);
    }
    return res;
  }
};
