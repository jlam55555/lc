// Real lazy here but this passes.
class MyHashSet {
public:
  void add(int key) { bs_.set(key); }

  void remove(int key) { bs_.reset(key); }

  bool contains(int key) { return bs_.test(key); }

private:
  std::bitset<1000001> bs_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
