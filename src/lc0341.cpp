/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// Keeps a stack of the current position in the list.
// Should always be pointing at the first valid remaining position
// in the list.
class NestedIterator {
  std::optional<int> prefetch{0};
  std::vector<std::pair<std::vector<NestedInteger> *, int>> pos_;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    // Note: it is guaranteed from the problem that we don't
    // have empty lists.
    auto *it = &nestedList;
    pos_.push_back({it, -1});
    next();
  }

  int next() {
    auto &[it, pos] = pos_.back();
    ++pos;
    // If we're at the end of a list, backtrack.
    if (pos == it->size()) {
      pos_.pop_back();
      // We've reached the end. Reset the prefetched value.
      if (pos_.empty()) {
        auto res = *prefetch;
        prefetch.reset();
        return res;
      }
      return next();
    }
    // If the current element is a list,
    // recurse into it.
    if (!(*it)[pos].isInteger()) {
      pos_.push_back({&(*it)[pos].getList(), -1});
      return next();
    }
    // The current element is an integer. Return it.
    auto res = *prefetch;
    prefetch = (*it)[pos].getInteger();
    return res;
  }

  bool hasNext() { return !!prefetch; }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
