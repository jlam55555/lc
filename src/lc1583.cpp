class Solution {
public:
  int unhappyFriends(int n, vector<vector<int>> &preferences,
                     vector<vector<int>> &pairs) {

    // reformat preferences chart
    for (int i = 0; i < n; ++i) {
      vector<int> newPreferences(n + 1);
      for (int j = 0; j < n - 1; ++j) {
        // cout << preferences[i][j] << " " << newPreferences.size() << endl;
        newPreferences[preferences[i][j]] = j;
      }
      preferences[i] = newPreferences;
    }

    int count = 0;
    for (int i = 0; i < pairs.size(); ++i) {

      int f1 = pairs[i][0], s1 = pairs[i][1];

      bool fu = false, su = false;

      for (int j = 0; j < pairs.size(); ++j) {
        if (i == j)
          continue;

        int f2 = pairs[j][0], s2 = pairs[j][1];

        // see if f1 prefers f2 and f2 prefers f1
        if (preferences[f1][f2] < preferences[f1][s1] &&
            preferences[f2][f1] < preferences[f2][s2]) {
          // cout << f1 << " " << f2 << endl;
          fu = true;
        }

        // see if f1 prefers s2 and s2 prefers f1
        else if (preferences[f1][s2] < preferences[f1][s1] &&
                 preferences[s2][f1] < preferences[s2][f2]) {
          // cout << f1 << " " << s2 << endl;
          fu = true;
        }

        // see if s1 prefers f2 and f2 prefers s1
        if (preferences[s1][f2] < preferences[s1][f1] &&
            preferences[f2][s1] < preferences[f2][s2]) {
          // cout << s1 << " " << f2 << endl;
          su = true;
        }

        // see if s1 prefers s2 and s2 prefers s1
        else if (preferences[s1][s2] < preferences[s1][f1] &&
                 preferences[s2][s1] < preferences[s2][f2]) {
          // cout << s1 << " " << s2 << endl;
          su = true;
        }
      }
      count += fu + su;
    }
    return count;
  }
};
