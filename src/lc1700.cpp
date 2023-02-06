class Solution {
public:
  // Algorithm:
  // - Since the students loop around, it doesn't matter what order
  //   they are in. It only matters which order the sandwiches are in;
  //   once we run out of sandwiches of one type, we're done.
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    // Count preferences.
    int prefs[2]{};
    for (auto s : students) {
      ++prefs[s];
    }

    // Iterate through sandwiches until we run out of one
    // type of sandwich; everything after that is blocked.
    int i{};
    while (i < sandwiches.size() && prefs[sandwiches[i]]) {
      --prefs[sandwiches[i++]];
    }

    return sandwiches.size() - i;
  }
};
