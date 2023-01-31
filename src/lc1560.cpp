class Solution {
public:
  // See better solution by lee215: Just need start and end points.
  vector<int> mostVisited(int n, vector<int> &rounds) {
    // Use zero-indexed.
    int freqs[100]{};
    int max_freq{};
    int j;
    for (int i{1}; i < rounds.size(); ++i) {
      // Do round.
      for (j = rounds[i - 1] - 1; j != rounds[i] - 1; j = (j + 1) % n) {
        max_freq = std::max(max_freq, ++freqs[j]);
      }
    }
    // Fencepost problem.
    max_freq = std::max(max_freq, ++freqs[j]);

    std::vector<int> res;
    for (int i{}; i < n; ++i) {
      std::cout << i << " " << freqs[i] << " " << max_freq << std::endl;
      if (freqs[i] == max_freq) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};
