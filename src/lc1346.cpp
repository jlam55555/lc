class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    std::unordered_set<int> seen;
    for (auto i : arr) {
      if (!(i & 1) && seen.count(i / 2) || seen.count(i * 2)) {
        return true;
      }
      seen.insert(i);
    }
    return false;
  }
};
