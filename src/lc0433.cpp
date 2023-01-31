class Solution {
public:
  // almost literally copied and pasted from lc_0127

  char gc[4] = {'A', 'C', 'G', 'T'};

  // time: O(N*maxWordLen)
  // space: O(N)
  int minMutation(string beginWord, string endWord, vector<string> &wordList) {

    // edge case: b/c otherwise would require at least one change
    // also empty case
    if (beginWord == endWord) {
      return 1;
    }

    // time & space: O(N)
    unordered_set<string> unseen(wordList.begin(), wordList.end());

    // bfs: time: O(V + V*(maxWordLen*26))
    // time: O(N*maxWordLen)
    queue<pair<string, int>> q{};
    q.push({beginWord, 0});
    if (unseen.count(beginWord)) {
      unseen.erase(beginWord);
    }

    int curDepth = 1;
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        auto wordDistPair = q.front();
        q.pop();

        string word = wordDistPair.first;
        int dist = wordDistPair.second;

        // loop through char
        // loop through each possible replacement
        // O(maxWordLen * 26)
        for (int charInd = 0; charInd < word.length(); ++charInd) {
          for (int i = 0; i < 4; ++i) {
            char c = gc[i];
            if (c == word[charInd]) {
              continue;
            }

            char tmp = word[charInd];
            word[charInd] = c;

            // check if word exists and has not been visited
            // if so, add to queue
            if (unseen.count(word) > 0) {
              // termination condition
              if (word == endWord) {
                return curDepth;
              }

              q.push({word, dist + 1});
              unseen.erase(word);
            }

            word[charInd] = tmp;
          }
        }
      }
      ++curDepth;
    }

    // no sequence exists
    return -1;
  }
};
