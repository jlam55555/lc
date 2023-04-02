// Search for the number of potions >= ceil(success/spells[i])
//
// This is the first solution in the editorial. I also thought
// of the second solution, which involves sorting both potions
// and spells and iterating over both sorted arrays in one pass
// (thus eliminating the binary search on each spell iteration).
// This first solution is simpler though.
//
// Trying out `std::transform` here, although it's longer than
// using a regular for-range loop.
class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    std::sort(potions.begin(), potions.end());
    auto it1{potions.begin()}, it2{potions.end()};
    std::vector<int> res;
    std::transform(
        spells.begin(), spells.end(), std::back_inserter(res), [=](int spell) {
          return std::distance(
              std::lower_bound(it1, it2, (success + spell - 1) / spell), it2);
        });
    return res;
  }
};
