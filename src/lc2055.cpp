typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
    // find first | and last | in range, find difference

    map<int, int> pipes{};
    int pipeCount = 0;

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '|') {
        pipes[i] = pipeCount++;
      }
    }

    vi res{};
    for (const vi &q : queries) {
      // find left and right pipes
      auto first = pipes.lower_bound(q[0]), last = pipes.upper_bound(q[1]);

      // should never happen
      if (last != pipes.begin()) {
        --last;
      }

      // no pipes in range
      if (first == pipes.end() || first->first > last->first) {
        res.push_back(0);
        continue;
      }

      res.push_back(last->first - first->first + 1 -
                    (last->second - first->second + 1));
    }

    return res;
  }
};
