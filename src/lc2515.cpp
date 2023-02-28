class Solution {
public:
  int closetTarget(vector<string> &words, string target, int startIndex) {
    int n(words.size());
    for (int i{}; i <= n / 2; ++i) {
      if (words[(startIndex + i) % n] == target ||
          words[(startIndex + n - i) % n] == target) {
        return i;
      }
    }
    return -1;
  }
};
