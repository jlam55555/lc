class MyCircularDeque {

  int frontIndex, lastIndex, *bs, len;

public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k) {
    frontIndex = 1;
    lastIndex = 0;

    bs = new int[k + 1];
    this->len = k + 1;
  }

  ~MyCircularDeque() { delete[] bs; }

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value) {
    if (isFull())
      return false;

    frontIndex = (frontIndex - 1 + len) % len;
    bs[frontIndex] = value;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value) {
    if (isFull())
      return false;

    lastIndex = (lastIndex + 1) % len;
    bs[lastIndex] = value;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront() {
    if (isEmpty())
      return false;

    frontIndex = (frontIndex + 1) % len;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast() {
    if (isEmpty())
      return false;

    lastIndex = (lastIndex - 1 + len) % len;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront() { return isEmpty() ? -1 : bs[frontIndex]; }

  /** Get the last item from the deque. */
  int getRear() { return isEmpty() ? -1 : bs[lastIndex]; }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() { return (lastIndex + 1) % len == frontIndex; }

  /** Checks whether the circular deque is full or not. */
  bool isFull() { return (lastIndex + 2) % len == frontIndex; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
