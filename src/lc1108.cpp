class Solution {
public:
  string defangIPaddr(string address) {
    string res(address.length() + 6, ' ');

    for (int i = 0, j = 0; i < address.length(); ++i) {
      if (address[i] == '.') {
        res[j++] = '[';
        res[j++] = '.';
        res[j++] = ']';
      } else {
        res[j++] = address[i];
      }
    }
    return res;
  }
};
