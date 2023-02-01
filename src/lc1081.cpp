class Solution {
public:
  // See lc0316 for the algorithm.
  string smallestSubsequence(string s) {

    // Keep track of last index of each char.
    int last[26]{};
    for (int i{}; i < s.length(); ++i) {
      last[s[i] - 'a'] = i;
    }

    // Try to keep in order.
    bool seen[26]{};
    std::string stk;
    for (int i{}; i < s.length(); ++i) {
      auto c{s[i]};

      // Letter already exists at a better position in the array.
      if (seen[c - 'a']) {
        continue;
      }

      // Try to pop earlier letters from the array.
      while (!stk.empty() && c < stk.back() && i < last[stk.back() - 'a']) {
        seen[stk.back() - 'a'] = 0;
        stk.pop_back();
      }
      stk.push_back(c);
      seen[stk.back() - 'a'] = 1;
    }

    return stk;
  }
};
