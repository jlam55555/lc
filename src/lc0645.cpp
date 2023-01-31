class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    char found[10000] = {0};
    int duplicated = -1, missing = -1;

    for (auto val : nums) {
      found[val - 1]++;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (found[i] == 0) {
        missing = i + 1;
      } else if (found[i] == 2) {
        duplicated = i + 1;
      }
    }

    return vector<int>{duplicated, missing};
  }
};
