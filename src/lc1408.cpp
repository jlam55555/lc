class Solution {
public:
  vector<string> stringMatching(vector<string> &words) {
    std::sort(words.begin(), words.end(), [](const auto &w1, const auto &w2) {
      return w1.length() < w2.length();
    });

    std::vector<std::string> res;
    for (auto i{0}; i < words.size(); ++i) {
      for (auto j{i + 1}; j < words.size(); ++j) {
        if (words[j].find(words[i]) != std::string::npos) {
          res.push_back(words[i]);
          break;
        }
      }
    }

    return res;
  }
};
