class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {

    int sign = k > 0 ? 1 : -1;
    int absk = sign * k;
    vector<int> res(code.size(), 0);

    for (int i = 0; i < code.size(); ++i) {
      for (int j = 0; j < absk; ++j) {
        int l = (i + sign + sign * j);
        if (l >= code.size())
          l -= code.size();
        while (l < 0)
          l += code.size();
        res[i] += code[l];
      }
    }

    return res;
  }
};
