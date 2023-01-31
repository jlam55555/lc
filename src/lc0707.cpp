// can de-duplicate a lot of code here
class MyLinkedList {
  struct Node {
    int val;
    struct Node *next, *prev;
  };
  Node *head, *tail;

public:
  MyLinkedList() {
    head = new Node{};
    tail = new Node{};
    head->next = tail;
    tail->prev = head;
  }
  ~MyLinkedList() {
    // TODO: cleanup
  }
  void print() {
    // for debugging
    // Node *it = head->next;
    // cout << "list: " << endl;
    // while (it->next) {
    //     cout << it->val << " ";
    //     it = it->next;
    // }
    // cout << endl;
  }
  int get(int index) {
    Node *it = head->next;
    while (index--) {
      if (it == tail) {
        return -1;
      }
      it = it->next;
    }
    if (it == tail) {
      return -1;
    }
    print();
    return it->val;
  }

  void addAtHead(int val) {
    Node *node = new Node{val, head->next, head};
    head->next = node;
    node->next->prev = node;
    print();
  }

  void addAtTail(int val) {
    Node *node = new Node{val, tail, tail->prev};
    tail->prev = node;
    node->prev->next = node;
    print();
  }

  void addAtIndex(int index, int val) {
    Node *it = head->next;
    while (index--) {
      if (it == tail) {
        return;
      }
      it = it->next;
    }
    Node *node = new Node{val, it, it->prev};
    node->prev->next = node;
    node->next->prev = node;
    print();
  }

  void deleteAtIndex(int index) {
    Node *it = head->next;
    while (index--) {
      if (it == tail) {
        return;
      }
      it = it->next;
    }
    if (it == tail) {
      return;
    }
    it->next->prev = it->prev;
    it->prev->next = it->next;
    delete it;
    print();
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
