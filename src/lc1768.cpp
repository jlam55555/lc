class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int i{};
    std::string res;
    while (i < word1.length() && i < word2.length()) {
      res.push_back(word1[i]);
      res.push_back(word2[i++]);
    }
    res += word1.substr(i);
    res += word2.substr(i);
    return res;
  }
};
