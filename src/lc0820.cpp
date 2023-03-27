// I initially did a Trie solution, but peeked at some
// of the solutions and realized that this solution is much
// simpler and uses much less memory (everything is in-place).
// The idea is that we use a lexicographic sort to do most
// of the heavy-lifting; then, if a word is a prefix of
// another word, then it will appear just before one of
// the elements that it is a prefix for.
//
// Old solution:
// Do a trie from the end of the words, count the sum
// of the terminal word lengths in the trie. Since we
// don't care about intermediate nodes, we don't need a
// `is_word` flag for each `ReverseTrie::Node`. This solution
// works, it just involves a lot of dynamic heap allocation
// for each of the nodes.
class Solution {
public:
  bool StartsWith(std::string_view haystack, std::string_view needle) {
    int m(haystack.length()), n(needle.length());
    if (m < n) {
      return false;
    }
    for (int i{}; i < n; ++i) {
      if (needle[i] - haystack[i]) {
        return false;
      }
    }
    return true;
  }

  int minimumLengthEncoding(vector<string> &words) {
    for (auto &word : words) {
      std::reverse(word.begin(), word.end());
    }
    std::sort(words.begin(), words.end());

    int res{};
    for (int i{}, n(words.size()); i < n; ++i) {
      if (i != n - 1 && StartsWith(words[i + 1], words[i])) {
        continue;
      }
      res += words[i].length() + 1;
    }
    return res;
  }
};
