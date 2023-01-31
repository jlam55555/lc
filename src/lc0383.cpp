class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    std::unordered_map<int, int> hist{};
    for (auto c : magazine) {
      ++hist[c];
    }
    for (auto c : ransomNote) {
      if (!hist[c]--) {
        return false;
      }
    }
    return true;
  }
};
