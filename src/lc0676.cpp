// I see two reasonable algorithms:
// - Store all words in a hashtable, and then try all modifications
//   when looking up a word. Or, conversely, store all words with
//   all their splits in the hashtable, which will make the lookup
//   faster but use a lot more space.
// - Use a trie and search for all words that have one modification
//   from the search word.
//
// I'm a little lazy so I go with the first approach. This is not very
// fast but it's probably about as efficient as you can get for space.
class MagicDictionary {
  std::unordered_set<std::string> dict_;

public:
  MagicDictionary() {}

  void buildDict(vector<string> dict) {
    dict_ = std::unordered_set<std::string>(dict.begin(), dict.end());
  }

  bool search(string word) {
    int n(word.size());
    for (int i{}; i < n; ++i) {
      char orig{word[i]};
      for (char c{'a'}; c <= 'z'; ++c) {
        if (c == orig) {
          continue;
        }
        word[i] = c;
        if (dict_.count(word)) {
          return true;
        }
      }
      word[i] = orig;
    }
    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
