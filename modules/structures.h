#include "constants.h"
#include "imports.h"
class TreeNode {
 private:
  static TreeNode* insertLevelOrder(vector<int> ra, int i) {
    if (ra[i] != INVALID_VALUE && i < ra.size())
      return new TreeNode(ra[i], insertLevelOrder(ra, 2 * i + 1),
                          insertLevelOrder(ra, 2 * i + 2));
    return nullptr;
  }

 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  void assign(int val = 0, TreeNode* left = nullptr,
              TreeNode* right = nullptr) {
    this->val = val;
    this->left = left;
    this->right = right;
  }
  void assign(TreeNode* root) {
    this->assign(root->val, root->left, root->right);
  }

  TreeNode() { this->assign(); }
  TreeNode(int x) { this->assign(x); }
  TreeNode(int x, TreeNode* left, TreeNode* right) {
    this->assign(x, left, right);
  }
  TreeNode(vector<int> x) {
    TreeNode* tree = this->insertLevelOrder(x, 0);
    this->assign(tree);
  }
};
class ListNode {
 public:
  int val;
  ListNode* next;
  ListNode() {
    this->val = 0;
    this->next = nullptr;
  }
  ListNode(int x) {
    this->val = x;
    this->next = nullptr;
  }
  ListNode(int x, ListNode* next) {
    this->val = x;
    this->next = next;
  }
  ListNode(vector<int>& x) { this->assign(x); }
  void append(int x) {
    ListNode* new_node = new ListNode(x);
    ListNode* curr = this->next;
    while (curr != nullptr && curr->next != nullptr) curr = curr->next;
    curr->next = new_node;
  }
  void assign(vector<int>& x) {
    if (x.size() <= 0) return;
    this->val = x[0];
    this->next = nullptr;
    ListNode* end = this;
    for (int i = 1; i < x.size(); i++) {
      ListNode* new_end = new ListNode(x[i]);
      end->next = new_end;
      end = end->next;
    }
    return;
  }
};

template <typename T>
class RingArray {
  static const int STARTING_CAPACITY = 10;
  static const int GROWTH_FACTOR = 2;
  static int mod(int a, int b) { return (a % b + b) % b; }

  T* arr;
  int lo, hi, capacity;
  int getActualIndex(int index) { return (this->lo + index) % this->capacity; }
  int getApparentIndex(int index) {
    if (index >= this->lo) return index - this->lo;
    return index + (this->capacity - this->lo);
  }
  void insertInitial(T val) {
    this->lo = 0;
    this->hi = 0;
    this->arr[this->hi++] = val;
  }
  void grow() {
    int newCapacity = capacity * GROWTH_FACTOR;
    T* newArr = (T*)malloc(newCapacity * sizeof(T));
    int newLo = 0, newHi = 0;
    for (int i = 0; i < size(); i++) {
      newArr[newHi++] = this->get(i);
    }

    this->lo = newLo;
    this->hi = newHi;
    this->capacity = newCapacity;
    free(this->arr);
    this->arr = newArr;
  }

 public:
  RingArray() {
    this->arr = (T*)malloc(STARTING_CAPACITY * sizeof(T));
    this->capacity = STARTING_CAPACITY;
    this->makeEmpty();
  }
  bool isEmpty() {
    if (this->lo == this->hi && this->lo == -1) {
      return true;
    }
    return false;
  }
  void makeEmpty() {
    this->lo = -1;
    this->hi = -1;
  }
  int size() {
    if (this->isEmpty()) return 0;
    if (this->lo == this->hi) return capacity;
    return this->getApparentIndex(hi);
  }
  void set(int index, int value) {
    if (index >= this->size()) {
      throw out_of_range("Index is out of range");
    }
    this->arr[getActualIndex(index)] = value;
  }
  T get(int index) {
    if (index >= this->size()) {
      throw out_of_range("Index is out of range");
    }
    return arr[getActualIndex(index)];
  }
  void push_back(T val) {
    // cout << "push_back " << val << "\n";
    if (this->isEmpty()) {
      return insertInitial(val);
    }
    if (this->size() >= this->capacity) {
      this->grow();
    }
    this->lo = mod(this->lo - 1, capacity);
    this->arr[this->lo] = val;
  }
  void push_front(T val) {
    // cout << "push_front " << val << "\n";
    if (this->isEmpty()) {
      return insertInitial(val);
    }
    if (this->size() >= this->capacity) {
      this->grow();
    }
    this->arr[this->hi] = val;
    this->hi = mod(this->hi + 1, capacity);
  }
  T pop_front() {
    // cout << "pop_front" << endl;
    if (this->isEmpty()) {
      return NULL;
    }
    T front = this->arr[this->lo];
    this->lo = mod(this->lo + 1, capacity);
    if (this->lo == this->hi) {
      this->makeEmpty();
    }
    return front;
  }
  T pop_back() {
    // cout << "pop_back" << endl;
    if (this->isEmpty()) {
      return NULL;
    }
    T back = this->arr[this->hi];
    this->hi = mod(this->hi - 1, capacity);
    if (this->lo == this->hi) {
      this->makeEmpty();
    }
    return back;
  }
  string toString() {
    if (this->size() <= 0) return "<empty>";
    string result = "(size = " + to_string(this->size()) +
                    ", capacity = " + to_string(this->capacity) + ")\t";
    result += "[";
    for (int i = 0; i < this->size() - 1; i++) {
      result += to_string(this->get(i)) + ", ";
      // cout << this->get(i) << ", ";
    }
    result += to_string(this->get(this->size() - 1));
    result += "]";
    return result;
  }
};