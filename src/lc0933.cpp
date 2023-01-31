class RecentCounter {
public:
  int ping(int t) {
    q_.push(t);
    while (t - q_.front() > 3000) {
      q_.pop();
    }
    return q_.size();
  }

private:
  std::queue<int> q_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
