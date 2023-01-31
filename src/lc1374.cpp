class Solution {
public:
  string generateTheString(int n) {
    std::string res(n, 'a');
    res[0] += !(n & 1);
    return res;
  }
};
