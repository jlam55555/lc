class Solution {
public:
  // modifies r1
  vector<int> add_rows(vector<int> &r1, vector<int> &r2) {
    int carry = 0;
    vector<int> res{};
    for (int i = 0; i < r1.size() || i < r2.size() || carry; ++i) {
      int d1 = (i >= r1.size()) ? 0 : r1[i];
      int d2 = (i >= r2.size()) ? 0 : r2[i];

      res.push_back((d1 + d2 + carry) % 10);
      carry = (d1 + d2 + carry) / 10;
    }
    return res;
  }

  string vec_to_str(vector<int> &res) {
    string r(res.size(), ' ');
    for (int i = 0; i < res.size(); ++i) {
      r[i] = res[i] + '0';
    }
    reverse(r.begin(), r.end());
    return r;
  }

  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    int n1 = num1.length(), n2 = num2.length();

    vector<int> row_sum{};

    for (int i = n1 - 1; i >= 0; --i) {
      int c1 = num1[i] - '0';

      // multiply second number by num1[i], shift left
      // by (n1-1-i) zero's
      vector<int> row(n1 - 1 - i, 0);
      int carry = 0;
      for (int j = n2 - 1; j >= 0 || carry; --j) {
        int c2 = j < 0 ? 0 : (num2[j] - '0');

        int digit = (c1 * c2 + carry) % 10;
        carry = (c1 * c2 + carry) / 10;

        row.push_back(digit);
      }

      row_sum = add_rows(row_sum, row);
    }

    return vec_to_str(row_sum);
  }
};
