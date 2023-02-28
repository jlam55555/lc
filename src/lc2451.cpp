class Solution {
public:
  bool Different(std::string_view w1, std::string_view w2) {
    for (int i{}, n(w1.length()); i < n - 1; ++i) {
      if (w1[i + 1] - w1[i] != w2[i + 1] - w2[i]) {
        return true;
      }
    }
    return false;
  }

  string oddString(vector<string> &words) {
    int n(words[0].length());

    // Compare difference array of w1 to w2 ... wm.
    // If w2 is different, then compare to w3.
    // Otherwise the first one that is different is
    // the answer.
    if (Different(words[0], words[1])) {
      return Different(words[0], words[2]) ? words[0] : words[1];
    }

    for (int i{2}, m(words.size()); i < m; ++i) {
      if (Different(words[0], words[i])) {
        return words[i];
      }
    }
    throw logic_error{"shouldn't happen"};
  }
};
