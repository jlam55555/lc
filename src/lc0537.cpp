class Solution {
public:
  struct cmplx {
    int real, imag;
  };

  struct cmplx stoc(string s) {
    auto plusPos = s.find('+');

    string real = s.substr(0, plusPos);
    string imag = s.substr(plusPos + 1, s.length() - 1);

    return cmplx{stoi(real), stoi(imag)};
  }

  string ctos(struct cmplx c) {
    return to_string(c.real) + "+" + to_string(c.imag) + "i";
  }

  string complexNumberMultiply(string a, string b) {
    struct cmplx ac = stoc(a), bc = stoc(b),
                 res = cmplx{ac.real * bc.real - ac.imag * bc.imag,
                             ac.real * bc.imag + bc.real * ac.imag};

    return ctos(res);
  }
};
