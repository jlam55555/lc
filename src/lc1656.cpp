#define bad "amsdlamd"

class OrderedStream {
public:
  vector<string> bs;
  int current = 0;

  OrderedStream(int n) {
    bs.resize(n);
    for (int i = 0; i < n; ++i) {
      bs[i] = bad;
    }
  }

  vector<string> insert(int id, string value) {
    id--;

    bs[id] = value;

    auto it1 = bs.begin(), it2 = bs.begin();
    advance(it1, current);

    for (; current < bs.size() && bs[current] != bad; ++current)
      ;

    advance(it2, current);

    return vector<string>(it1, it2);
  }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
