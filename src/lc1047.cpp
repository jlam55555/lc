class Solution {
public:
  string removeDuplicates(string s) {
    std::string stk;
    for (auto c : s) {
      if (stk.back() == c) {
        stk.pop_back();
      } else {
        stk.push_back(c);
      }
    }
    return stk;
  }
};
