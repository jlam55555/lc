// Idea: Try to find a zero between each pair
// of equal numbers. (Note that two pairs cannot
// share the same zero).
//
// This uses some nontrivial searching magic to find the
// earliest zero that matches the constraints, which is slightly
// harder than most Leetcode mediums I've seen. It does
// beat most of the existing solutions though.
//
// The question is kinda nonsensical though. First, we start with
// an infinite number of lakes, we can flood a lake by raining for
// two days on it, we can mop up a lake in one day, all the lakes
// initially start dried up, and the title is "Avoid Flood in
// The City" (where does the "city" come from?). Anywho...
class Solution {
public:
  vector<int> avoidFlood(vector<int> &rains) {
    int n(rains.size());
    std::set<int> zeros;
    std::vector<int> res(n);
    std::unordered_map<int, int> last;

    for (int i{}; i < n; ++i) {
      if (!rains[i]) {
        res[i] = 1;
        zeros.insert(i);
        continue;
      }

      // Seen it before, need a zero in between.
      // Find the earliest possible zero that we can use.
      if (auto it{last.find(rains[i])}; it != last.end()) {
        auto zero_loc{zeros.upper_bound(it->second)};
        if (zero_loc == zeros.end()) {
          return {};
        }
        res[*zero_loc] = rains[i];
        zeros.erase(zero_loc);
      }
      last[rains[i]] = i;
      res[i] = -1;
    }

    return res;
  }
};
