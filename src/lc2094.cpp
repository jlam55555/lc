class Solution {
public:
  // Algorithm: Iterate over all possibilities of first,
  // second, and third digits while keeping constraints
  // in mind.
  vector<int> findEvenNumbers(vector<int> &digits) {
    int freqs[10]{};
    for (auto digit : digits) {
      ++freqs[digit];
    }

    std::vector<int> res;
    for (int i{1}; i < 10; ++i) {
      if (!freqs[i]) {
        continue;
      }
      --freqs[i];
      for (int j{}; j < 10; ++j) {
        if (!freqs[j]) {
          continue;
        }
        --freqs[j];
        for (int k{}; k < 10; k += 2) {
          if (freqs[k]) {
            res.push_back(100 * i + 10 * j + k);
          }
        }
        ++freqs[j];
      }
      ++freqs[i];
    }
    return res;
  }
};
