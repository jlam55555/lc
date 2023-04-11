// A prototypical stack question. There are a few
// Leetcode questions that are very similar to this
// (search this directory for lc1047.cpp).
//
// Here I show a typical stack implementation, as
// well as an in-place stack implementation.
class Solution {
public:
  // Easier to implement solution using a stack
  // data structure (implemented as a string).
  string removeDuplicates_typical(string s) {
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

  // A little trickier, but in-place. We basically
  // maintaing the stack in the already-seen part
  // of `s`.
  string removeDuplicates(string s) {
    int i{};
    for (int j{}, n(s.length()); j < n; ++j) {
      if (i && s[i - 1] == s[j]) {
        --i;
      } else {
        s[i++] = s[j];
      }
    }
    s.resize(i);
    return s;
  }
};
