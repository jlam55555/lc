class Solution {

public:
  int findLHS(vector<int> &nums) {

    std::unordered_map<int, int> freq;

    auto longest{INT_MIN};

    for (auto i : nums) {

      ++freq[i];
    }

    // Find longest where the previous or next number

    // also exists.

    const std::unordered_map<int, int> freq2{freq.begin(), freq.end()};

    for (const auto &i : freq2) {

      if (i.second && freq[i.first + 1]) {

        longest = std::max(longest, i.second + freq[i.first + 1]);
      }
    }

    return longest == INT_MIN ? 0 : longest;
  }
};
