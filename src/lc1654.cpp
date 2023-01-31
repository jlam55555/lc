class node {
public:
  int val, depth, stepsBackward;
};

class Solution {
public:
  int minimumJumps(vector<int> &forbidden, int a, int b, int x) {

    int len = 4000;
    int *dp = new int[len];
    memset(dp, 0, len * sizeof(int));

    set<int> s{forbidden.begin(), forbidden.end()};
    queue<node> q{};
    q.push(node{0, 0, 0});

    if (!x)
      return 0;

    while (!q.empty()) {
      node curr = q.front();
      q.pop();
      int val = curr.val;
      int depth = curr.depth;
      int stepsBackward = curr.stepsBackward;

      // cout << val << " " << depth << endl;

      if (dp[val])
        continue;
      dp[val] = depth;

      // cout << "testing" << endl;

      if (stepsBackward < 1 && val - b > 0 && !s.count(val - b)) {
        if (val - b == x) {
          return depth + 1;
        }
        q.push(node{val - b, depth + 1, stepsBackward + 1});
      }

      // if (val == 6) {
      //     cout << (val + a < len ? "true" : "false") << " " << (!s.count(val
      //     + a) ? "true" : "false") << endl;
      // }

      if (val + a < len && !s.count(val + a)) {
        if (val + a == x) {
          return depth + 1;
        }
        q.push(node{val + a, depth + 1, 0});
      }
    }

    return -1;
  }
};
