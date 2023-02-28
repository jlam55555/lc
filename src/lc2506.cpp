class Solution {
public:
  int similarPairs(vector<string> &words) {
    std::unordered_map<std::string, int> freqs;
    for (const auto &word : words) {
      std::set<char> uniqc{word.begin(), word.end()};
      ++freqs[std::string{uniqc.begin(), uniqc.end()}];
    }

    int res{};
    for (const auto [unused, freq] : freqs) {
      res += freq * (freq - 1);
    }
    return res / 2;
  }
};
