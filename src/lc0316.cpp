class Solution {
public:
  // Go through string. Try to keep letters sorted.
  //
  // If a lettter has already been seen, don't do
  // anything. This ensures that we don't duplicate
  // elements.
  //
  // If a letter is larger than the previous one,
  // then we are sorted.
  //
  // If a letter is smaller than the previous one,
  // try to pop previous elements if they appear later
  // in the string. Note that this guarantees that all
  // letters exist in the resulting string.
  //
  // To do this, we have to keep track of the last index
  // of each character in the string.
  string removeDuplicateLetters(string s) {

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
