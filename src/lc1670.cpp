class ll {
public:
  ll *prev, *next;
  int val;
};

class FrontMiddleBackQueue {
public:
  ll *head, *tail, *mid;
  int length, middle;

  FrontMiddleBackQueue() {
    length = 0;
    head = new ll{nullptr, nullptr, -1};
    tail = new ll{head, nullptr, -1};
    mid = tail;
    head->next = tail;
  }

  void pushFront(int val) {
    head->next = new ll{head, head->next, val};
    head->next->next->prev = head->next;
    if (length % 2 == 0) {
      mid = mid->prev;
    }
    if (!length)
      mid = head->next;
    ++length;
  }

  void pushMiddle(int val) {
    if (!length)
      mid = tail;
    mid->prev = new ll{mid->prev, mid, val};
    mid->prev->prev->next = mid->prev;
    if (length % 2 == 0) {
      mid = mid->prev;
    }
    if (!length)
      mid = head->next;
    ++length;
  }

  void pushBack(int val) {
    tail->prev = new ll{tail->prev, tail, val};
    tail->prev->prev->next = tail->prev;
    if (length % 2 == 1) {
      mid = mid->next;
    }
    if (!length)
      mid = head->next;
    ++length;
  }

  int popFront() {
    if (!length)
      return -1;
    int rv = head->next->val;
    head->next = head->next->next;
    head->next->prev = head;
    if (length % 2 == 1) {
      mid = mid->next;
    }
    --length;
    return rv;
  }

  int popMiddle() {
    if (!length)
      return -1;

    int rv;
    if (length % 2 == 0) {
      rv = mid->prev->val;
      mid->prev->prev->next = mid;
      mid->prev = mid->prev->prev;
    } else {
      rv = mid->val;
      mid->prev->next = mid->next;
      mid->next->prev = mid->prev;
      mid = mid->next;
    }
    --length;
    return rv;
  }

  int popBack() {
    if (!length)
      return -1;
    int rv = tail->prev->val;
    tail->prev = tail->prev->prev;
    tail->prev->next = tail;
    if (length % 2 == 0) {
      mid = mid->prev;
    }
    --length;
    return rv;
  }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
