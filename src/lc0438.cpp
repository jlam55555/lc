class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    // get frequencies of characters in s
    int freq_map[26] = {0};
    int letter_count = 0;
    for (auto c : p) {
      if (++freq_map[c - 'a'] == 1) {
        ++letter_count;
      }
    }

    vector<int> res{};
    if (s.length() < p.length()) {
      return res;
    }

    //         for (int i = 0; i < 26; ++i) {
    //             cout << freq_map[i] << " ";
    //         }
    //         cout << endl;

    // build initial counts
    int i;
    for (i = 0; i < p.length(); ++i) {
      if (--freq_map[s[i] - 'a'] == 0) {
        --letter_count;
      }
    }

    // for (int i = 0; i < 26; ++i) {
    //     cout << freq_map[i] << " ";
    // }
    // cout << endl;

    vector<int> matches{};
    if (letter_count == 0) {
      matches.push_back(0);
    }

    // to detect whether a word is correct, count how many
    // letters match -- letter_count should be 0;
    // do the same but advance one letter at a time -- sliding window
    // technically this can be combined with the previous part
    // but it's nice to separate it like this
    for (i = 0; i < s.length() - p.length(); ++i) {
      // add a letter, check if that letter has the correct count
      if (--freq_map[s[i + p.length()] - 'a'] == 0) {
        --letter_count;
      }
      // remove a letter, check if that letter lost the correct count
      if (++freq_map[s[i] - 'a'] == 1) {
        ++letter_count;
      }

      // check if all letters have their correct count
      if (letter_count == 0) {
        matches.push_back(i + 1);
      }
    }

    return matches;
  }
};
