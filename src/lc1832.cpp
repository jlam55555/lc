class Solution {
public:
  bool checkIfPangram(string sentence) {
    bool freqs[26]{};
    int count{};
    for (auto c : sentence) {
      if (!freqs[c - 'a']) {
        if (++count == 26) {
          return true;
        }
        freqs[c - 'a'] = 1;
      }
    }
    return false;
  }
};
