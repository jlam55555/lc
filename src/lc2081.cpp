class Solution {
public:
  vector<string> mirror1{""}, mirror2{"0"};
  long long toBase10(string &num, int k) {
    long long res = 0;
    for (int i = 0; i < num.size(); ++i)
      res = res * k + (num[i] - '0');
    return res;
  }
  bool IsMirror(long long num) {
    auto s = to_string(num);
    for (int i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - i - 1])
        return false;
    }
    return true;
  }
  long long dfs(int dig, int n, int k) {
    vector<string> mirror;
    long long res = 0;
    if (n == 0)
      return 0;
    for (int i = 0; n > 0 && i < k; ++i) {
      for (int j = 0; n > 0 && j < mirror1.size(); ++j) {
        mirror.push_back(to_string(i) + mirror1[j] + to_string(i));
        long long n10 = toBase10(mirror.back(), k);
        if (i != 0 && IsMirror(n10)) {
          res += n10;
          --n;
        }
      }
    }
    swap(mirror1, mirror2);
    swap(mirror2, mirror);
    return res + dfs(dig + 1, n, k);
  }
  long long kMirror(int k, int n) {
    long long res = 0;
    for (int i = 1; n > 0 && i < k; ++i) {
      mirror2.push_back(to_string(i));
      res += i;
      --n;
    }
    return res + dfs(2, n, k);
  }
};
