class MyHashMap {
  static constexpr int primes[] = {101,  199,  401,   797,   1601,
                                   3203, 6397, 12799, 25601, 51199},
                       primes_len = sizeof(primes) / sizeof(int);

  struct entry {
    int key, value;
    bool deleted = false, occupied = false;
  };

  vector<entry> data;
  int count;

  // https://stackoverflow.com/a/12996028/2397327
  unsigned hash(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % data.size();
  }

  int find(int key, bool include_deleted = false) {
    int i;

    // TODO: should also check if wrapped around all the way
    for (i = hash(key);
         data[i].occupied &&
         ((include_deleted ? 0 : data[i].deleted) || data[i].key != key);
         ++i, i %= data.size())
      ;

    return i;
  }

  int rehash() {
    int i;

    for (i = 0; primes[i] <= data.size() && i < primes_len; ++i) {
    }
    if (i == primes_len) {
      cerr << "ran out of primes" << endl;
      return -1;
    }

    auto old_data = move(data);
    data = vector<entry>(primes[i]);

    for (auto entry : old_data) {
      if (entry.occupied && !entry.deleted) {
        put(entry.key, entry.value);
      }
    }

    return 0;
  }

public:
  MyHashMap() : count{0}, data(primes[0]) {}

  void put(int key, int value) {
    int pos = find(key, true);

    if (data[pos].occupied) {
      data[pos].value = value;
      data[pos].deleted = false;
    } else {
      data[pos] = entry{key, value, false, true};
      if (++count > data.size() / 2) {
        rehash();
      }
    }
  }

  int get(int key) {
    int pos = find(key);

    if (data[pos].occupied) {
      return data[pos].value;
    } else {
      return -1;
    }
  }

  void remove(int key) {
    int pos = find(key);

    if (data[pos].occupied) {
      data[pos].deleted = true;
      --count;
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
