class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    unordered_map<string, int> m1{}, m2{};

    for (const auto &w : words1) {
      ++m1[w];
    }
    for (const auto &w : words2) {
      ++m2[w];
    }

    int count = 0;
    for (const auto &p : m1) {
      if (p.second == 1 && m2[p.first] == 1) {
        ++count;
      }
    }
    return count;
  }
};
