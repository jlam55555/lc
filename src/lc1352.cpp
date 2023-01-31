static int cumProd[40000] = {1};

class ProductOfNumbers {
  int curPos = 0;

public:
  void add(int num) {
    if (num) {
      cumProd[curPos + 1] = cumProd[curPos] * num;
      ++curPos;
    } else {
      curPos = 0;
    }
  }

  int getProduct(int k) {
    return k > curPos ? 0 : cumProd[curPos] / cumProd[curPos - k];
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
