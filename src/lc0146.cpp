class LRUCache {
  std::list<int> order_{};
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> bs_{};
  int capacity_;

public:
  LRUCache(int capacity) : capacity_{capacity} {}

  int get(int key) {
    // std::cout << "Get on key=" << key << std::endl;
    auto it = bs_.find(key);
    if (it == bs_.end()) {
      return -1;
    }
    order_.splice(order_.begin(), order_, it->second.second);
    return it->second.first;
  }

  void put(int key, int value) {
    // std::cout << "Put on key=" << key << " value=" << value << std::endl;
    auto it = bs_.find(key);
    if (it != bs_.end()) {
      // std::cout << "Key found, updating" << std::endl;
      order_.splice(order_.begin(), order_, it->second.second);
      it->second.first = value;
      return;
    }

    if (bs_.size() == capacity_) {
      // Perform LRU eviction.
      auto old_key = order_.back();
      // std::cout << "Evicting key=" << old_key << std::endl;
      order_.pop_back();
      bs_.erase(old_key);
    }

    auto new_it = order_.insert(order_.begin(), key);
    bs_[key] = std::make_pair(value, new_it);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
