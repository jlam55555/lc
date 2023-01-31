class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    //         set<string> s{};

    //         for (auto st : arr) {
    //             if (!s.count(st)) {
    //                 if (--k == 0) {
    //                     return st;
    //                 }
    //                 s.insert(st);
    //             }
    //         }

    unordered_map<string, int> s{};

    for (auto st : arr) {
      ++s[st];
    }

    for (auto st : arr) {
      if (s[st] == 1) {
        if (--k == 0) {
          return st;
        }
        ++s[st];
      }
    }

    return "";
  }
};
