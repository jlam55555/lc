class Solution {
public:
  int minimumEffort(vector<vector<int>> &tasks) {

    struct {
      bool operator()(vector<int> &a, vector<int> &b) const {
        return b[1] - b[0] < a[1] - a[0];
      }
    } customLess;

    sort(tasks.begin(), tasks.end(), customLess);

    int n = tasks.size();

    int curr = 0;
    for (int i = n - 1; i >= 0; --i) {
      curr = max(curr + tasks[i][0], tasks[i][1]);
    }

    return curr;
  }
};
