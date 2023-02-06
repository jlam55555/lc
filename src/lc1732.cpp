class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int alt{}, res{};
    for (auto g : gain) {
      res = std::max(res, alt += g);
    }
    return res;
  }
};
