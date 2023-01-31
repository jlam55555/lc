class Solution {
public:
  int numOfStrings(vector<string> &patterns, string word) {
    const char *w = word.c_str();

    int count = 0;
    for (auto s : patterns) {
      const char *word2 = s.c_str();
      count += (strstr(w, word2) != nullptr);
    }

    return count;
  }
};
