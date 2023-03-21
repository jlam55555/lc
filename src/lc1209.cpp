// This question uses a very similar algorithm to
// lc1047.cpp (Remove All Adjacent Duplicates in String),
// but we want to be a little more efficient since we can
// only remove duplicates greater than a (potentially large)
// length of k.
//
// To do this, we store the string using run-length encoding
// (RLE), which allows us to efficiently get the length of the
// last component of the string. At the end we convert it
// back into a string.
class Solution {
public:
  string removeDuplicates(string s, int k) {
    std::vector<std::pair<char, int>> rle;

    for (char c : s) {
      // Update RLE.
      if (rle.empty() || rle.back().first != c) {
        rle.push_back({c, 1});
      } else {
        ++rle.back().second;
      }

      // Perform removal.
      if (rle.back().second > k) {
        rle.back().second -= k;
      } else if (rle.back().second == k) {
        rle.pop_back();
      }
    }

    // Convert RLE back to string.
    std::string res;
    for (auto [c, freq] : rle) {
      res += std::string(freq, c);
    }
    return res;
  }
};
