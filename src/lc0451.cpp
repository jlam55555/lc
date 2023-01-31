#define N 127

class Solution {
public:
  string frequencySort(string s) {
    vector<vector<int>> hist(N, {0, 0});

    for (int i = 0; i < N; ++i)
      hist[i][1] = i;

    for (char c : s)
      ++hist[c][0];

    sort(hist.begin(), hist.end());

    string res = "";
    for (int i = N - 1; i >= 0; --i)
      res += string(hist[i][0], hist[i][1]);

    return res;
  }
};
