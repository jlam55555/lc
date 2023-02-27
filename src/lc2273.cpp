class Solution {
public:
  bool IsAnagram(std::string_view w1, std::string_view w2) {
    if (w1.length() != w2.length()) {
      return false;
    }
    int n(w1.length()), diff{}, hist[26]{};
    for (int i{}; i < n; ++i) {
      if (!hist[w1[i] - 'a']++) {
        ++diff;
      }
      if (!--hist[w2[i] - 'a']) {
        --diff;
      }
    }
    return !diff;
  }

  vector<string> removeAnagrams(vector<string> &words) {
    std::vector<std::string> res;
    for (const auto &word : words) {
      if (res.empty() || !IsAnagram(word, res.back())) {
        res.push_back(word);
      }
    }
    return res;
  }
};
