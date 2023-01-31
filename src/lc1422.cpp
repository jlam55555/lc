class Solution {
public:
  int maxScore(string s) {
    // Count total zeros and ones.
    int z{}, o{};
    for (auto c : s) {
      ++(c - '0' ? o : z);
    }

    // Split point after index i.
    int res{}, zc{}, oc{o};
    s.pop_back();
    for (auto c : s) {
      res = std::max(res, (zc += c == '0') + (oc -= c == '1'));
    }

    return res;
  }
};
