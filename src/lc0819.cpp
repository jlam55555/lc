class Solution {
public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    for (auto &c : paragraph) {
      c = std::tolower(c);
    }

    std::unordered_set<std::string> banned_map{banned.begin(), banned.end()};
    std::unordered_map<std::string, int> hist{};

    std::string most_freq_word;
    auto most_freq_count{0};

    for (auto i{0}; i < paragraph.size();) {
      // Get the word
      if (!std::isalpha(paragraph[i])) {
        ++i;
        continue;
      }
      auto j{i + 1};
      while (j < paragraph.size() && std::isalpha(paragraph[j])) {
        ++j;
      }
      auto word{paragraph.substr(i, j - i)};
      if (!banned_map.count(word)) {
        if (++hist[word] > most_freq_count) {
          most_freq_count = hist[word];
          most_freq_word = word;
        }
      }
      i = j;
    }

    return most_freq_word;
  }
};
