class Solution {
public:
  //     bool isPossibleDivide(vector<int>& nums, int k) {
  //         // holds start positions
  //         queue<int> dq;

  //         int len = nums.size();

  //         if (len % k != 0) {
  //             return false;
  //         }

  //         map<int,int> numMap;

  //         for (auto i : nums) {
  //             ++numMap[i];
  //         }

  //         // "check" all straights
  //         int lastChecked = -1, opened = 0;
  //         for (auto pair : numMap) {
  //             int n = pair.first, count = pair.second;

  //             // invalid straights
  //             if (opened && n > lastChecked+1
  //                 || opened > numMap[n]) {
  //                 return false;
  //             }

  //             // open straights
  //             dq.push(numMap[n] - opened);

  //             lastChecked = n;
  //             opened = numMap[n];

  //             if (dq.size() == k) {
  //                 opened -= dq.front();
  //                 dq.pop();
  //             }
  //         }

  //         // all straights are valid, make sure that we have the right number
  //         of straights return opened == 0;
  //     }

  bool isPossibleDivide(vector<int> &nums, int k) {

    int len = nums.size();

    if (len % k != 0) {
      return false;
    }

    map<int, int> numSet;
    for (int i : nums) {
      ++numSet[i];
    }

    for (int i = 0; i < len / k; ++i) {
      int n = numSet.begin()->first;

      if (--numSet[n] == 0) {
        numSet.erase(n);
      }

      for (int j = 1; j < k; ++j) {
        if (!numSet.count(++n)) {
          return false;
        }
        if (--numSet[n] == 0) {
          numSet.erase(n);
        }
      }
    }

    return true;
  }

  //     bool isPossibleDivide(vector<int>& nums, int k) {
  //     unordered_map<int,int> cnt, len;
  //     sort(nums.begin(), nums.end());
  //     for (auto &num: nums) {
  //         ++cnt[num];
  //     }
  //     for (auto &num: nums) {
  //         if (!cnt[num]) {
  //             continue;
  //         }
  //         int times = cnt[num];
  //         for (int i = 0; i < k; ++i) {
  //             if (cnt[num+i]-times < 0) {
  //                 return false;
  //             }
  //             cnt[num+i] -= times;
  //         }
  //     }
  //     return true;
  // }
};
