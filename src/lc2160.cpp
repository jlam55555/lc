class Solution {
public:
  int minimumSum(int num) {
    std::vector<int> n;
    while (num) {
      n.push_back(num % 10);
      num /= 10;
    }
    std::sort(n.begin(), n.end());
    return (n[0] + n[1]) * 10 + n[2] + n[3];
  }
};
