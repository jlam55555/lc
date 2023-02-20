class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    std::vector<std::string> res;
    int i{}, n(s.length());
    for (; i < n; i += k) {
      if (i + k > n) {
        res.push_back(s.substr(i) + std::string(i + k - n, fill));
      } else {
        res.push_back(s.substr(i, k));
      }
    }
    return res;
  }
};
