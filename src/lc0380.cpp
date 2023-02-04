class RandomizedSet {
  // Backing store.
  std::vector<int> bs_;

  // Mapping to backing store.
  std::unordered_map<int, int> lookup_;

public:
  RandomizedSet() {}

  bool insert(int val) {
    if (lookup_.count(val)) {
      return false;
    }
    int pos(lookup_.size());
    if (pos == bs_.size()) {
      bs_.push_back(val);
    } else {
      bs_[pos] = val;
    }
    lookup_[val] = pos;
    return true;
  }

  bool remove(int val) {
    auto it = lookup_.find(val);
    if (it == lookup_.end()) {
      return false;
    }
    std::swap(bs_[lookup_[val]], bs_[lookup_.size() - 1]);
    lookup_[bs_[lookup_[val]]] = lookup_[val];
    lookup_.erase(it);
    return true;
  }

  int getRandom() { return bs_[std::rand() % lookup_.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
