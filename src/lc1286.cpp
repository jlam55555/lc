class CombinationIterator {
public:
  string s, cs;
  vector<int> ints, cur;
  int l, cl;
  bool first;

  CombinationIterator(string characters, int combinationLength) {
    s = characters;
    cl = combinationLength;
    l = characters.length();
    for (int i = 0; i < cl; ++i) {
      cur.push_back(l - cl + i);
    }
    cs = s.substr(l - cl, cl);
    first = true;
  }

  string next() {
    // reverse the stack that has the same suffix as characters;
    int i;
    for (i = l - 1; !cur.empty() && cur.back() == i; --i) {
      cur.pop_back();
    }

    // at end, restart permutation
    if (cur.empty()) {
      i = 0;
    } else {
      i = cur.back() + 1;
      cur.pop_back();
    }

    for (; cur.size() < cl; ++i) {
      cs[cur.size()] = s[i];
      cur.push_back(i);
    }

    first = false;

    return cs;
  }

  bool hasNext() {
    if (first)
      return true;

    // check if the current is the suffix of characters
    for (int i = 0; i < cl; ++i) {
      if (cur[i] != l - cl + i) {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */
