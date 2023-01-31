class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    map<int, int> h;
    for (int i : nums) {
      h[i]++;
    }

    int count = 0;
    for (auto &it : h) {
      if (it.first > k / 2 || (k % 2 == 0 && it.first == k / 2)) {
        break;
      }

      count += min(h[k - it.first], it.second);
    }
    if (k % 2 == 0) {
      count += h[k / 2] / 2;
    }

    return count;
  }
};
