class Solution {
public:
  string sortString(string s) {
    std::map<char, int> freqs;
    std::string res;

    for (auto c : s) {
      ++freqs[c];
    }

    while (!freqs.empty()) {
      for (auto it{freqs.begin()}; it != freqs.end();) {
        res.push_back(it->first);
        if (!--it->second) {
          it = freqs.erase(it);
        } else {
          ++it;
        }
      }
      for (auto it{freqs.rbegin()}; it != freqs.rend();) {
        res.push_back(it->first);
        if (!--it->second) {
          // Seems like erase doesn't accept a reverse_iterator,
          // so we need to construct a regular iterator, then
          // convert it back to a reverse iterator.
          // https://stackoverflow.com/a/50282077
          it = decltype(it)(freqs.erase(std::next(it).base()));
        } else {
          ++it;
        }
      }
    }

    return res;
  }
};
