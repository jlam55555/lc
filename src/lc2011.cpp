class Solution {
public:
  int finalValueAfterOperations(vector<string> &operations) {
    int x = 0;
    for (auto s : operations) {
      if (s == "--X" || s == "X--")
        --x;
      else
        ++x;
    }
    return x;
  }
};
