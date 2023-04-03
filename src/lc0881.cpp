class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    std::sort(people.begin(), people.end());

    // Fit the biggest person with the smallest person
    // that'll also fit with them.
    int n(people.size()), l{}, r{n - 1}, res{};
    while (l <= r) {
      if (l < r && people[l] + people[r] <= limit) {
        ++l;
      }
      --r;
      ++res;
    }

    return res;
  }
};
