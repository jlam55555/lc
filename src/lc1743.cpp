class Solution {
public:
  class node {
  public:
    int left, right, count;

    node() {
      count = 0;
      left = INT_MIN;
      right = INT_MIN;
    }

    void addNext(int next) {
      if (!count) {
        left = next;
        ++count;
      } else {
        right = next;
      }
    }

    int getNext(int prev) { return right == prev ? left : right; }
  };

  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    unordered_map<int, node> seen{};
    unordered_set<int> seenOnce{};
    int i, j;

    // create list
    for (auto pair : adjacentPairs) {
      i = pair[0], j = pair[1];

      if (!seen.count(i)) {
        seen[i] = node{};
        seenOnce.insert(i);
      } else {
        seenOnce.erase(i);
      }

      if (!seen.count(j)) {
        seen[j] = node{};
        seenOnce.insert(j);
      } else {
        seenOnce.erase(j);
      }

      seen[i].addNext(j);
      seen[j].addNext(i);
    }

    int iter = *seenOnce.begin(), prev = INT_MIN, tmp;
    vector<int> res{};
    while (iter != INT_MIN) {
      res.push_back(iter);
      tmp = iter;
      iter = seen[iter].getNext(prev);
      prev = tmp;
    }

    return res;
  }
};
