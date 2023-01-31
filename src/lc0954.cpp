class Solution {
public:
  struct mySort {
    bool operator()(const int &i1, const int &i2) const {
      return abs(i1) < abs(i2);
    }
  };

  bool canReorderDoubled(vector<int> &arr) {

    // check if each number can be matched with a pair
    unordered_map<int, int> hist{};
    unordered_set<int> keys{};
    for (int i : arr) {
      ++hist[i];
      keys.insert(i);
    }

    vector<int> kv(keys.begin(), keys.end());
    sort(kv.begin(), kv.end(), mySort{});

    for (auto key : kv) {
      while (hist[key]) {
        --hist[key];
        // find a pair
        if (--hist[2 * key] < 0) {
          return false;
        }
      }
    }

    return true;
  }
};
