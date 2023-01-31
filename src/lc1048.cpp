class Solution {
public:
  int longestStrChain(vector<string> &words) {
    vector<vector<string>> bins(17);
    unordered_map<string, int> wordChainLengths{};

    // handle the case of zero
    if (words.empty()) {
      return 0;
    }

    // check that input is valid
    assert(words.size() >= 1 && words.size() <= 1000);

    // register all words by length and in hashtable
    for (string word : words) {
      bins[word.length()].push_back(word);
      wordChainLengths[word] = 1;
    }

    // find the max chain len, starting from longest length downwards
    int maxChainLen = 1;
    for (int i = 16; i >= 2; --i) {
      for (string word : bins[i]) {

        int curChainLength = wordChainLengths[word];

        // try to delete each character from the word,
        // check if it exists
        for (int j = 0; j < word.length(); ++j) {
          string newWord = word.substr(0, j) + word.substr(j + 1);

          if (wordChainLengths[newWord] > 0) {
            wordChainLengths[newWord] =
                max(wordChainLengths[newWord], curChainLength + 1);
            maxChainLen = max(maxChainLen, wordChainLengths[newWord]);
          }
        }
      }
    }

    return maxChainLen;
  }
};

// ["a","b","ba","bca","bda","bdca"]

// BINS
// 1   a   b
// 2   ba
// 3   bca bda
// 4   bdca

// WORDCHAINLENGTHS
// a       4
// b       4
// ba      3
// bca     2
// bda     2
// bdca    1

// i = 2
//     word = ba
//     ccl = 3
//     newWord = b
//     maxChainLen = 4
