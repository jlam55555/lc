class Solution {
public:
  int uniqueMorseRepresentations(const vector<string> &words) {
    const std::string letters[]{
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
    std::unordered_set<std::string> transformed{};
    for (const auto &word : words) {
      std::string transformed_word{};
      for (auto c : word) {
        transformed_word += letters[c - 'a'];
      }
      transformed.insert(transformed_word);
    }
    return transformed.size();
  }
};
