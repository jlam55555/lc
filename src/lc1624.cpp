class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    int res{-1};
    std::vector<int> last_ind(26, -1);
    for (int i{}; i < s.length(); ++i) {
      auto &prev_ind{last_ind[s[i] - 'a']};
      if (prev_ind != -1) {
        res = std::max(res, i - prev_ind - 1);
      } else {
        prev_ind = i;
      }
    }
    return res;
  }
};
