class Solution {
public:
  string decodeMessage(string key, string message) {
    std::vector<int> translation(26, -1);
    char cur{'a'};
    for (auto c : key) {
      if (c != ' ' && translation[c - 'a'] == -1) {
        translation[c - 'a'] = cur++;
      }
    }
    for (auto &c : message) {
      c = c == ' ' ? c : translation[c - 'a'];
    }
    return message;
  }
};
