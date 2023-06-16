#include "../modules/index.h"
class RandomizedSet {
  unordered_map<int, int> existsAt;
  RingArray<int> r;

 public:
  RandomizedSet() { r = RingArray<int>(); }

  bool insert(int val) {
    if (existsAt.find(val) != existsAt.end()) {
      return false;
    }
    r.push_front(val);
    existsAt[val] = r.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (existsAt.find(val) == existsAt.end()) {
      return false;
    }

    int index = existsAt[val];
    int lastVal = r.get(r.size() - 1);
    r.set(index, lastVal);
    existsAt[lastVal] = index;
    r.pop_back();
    existsAt.erase(val);
    return true;
  }

  int getRandom() {
    int n = rand() % r.size();
    return r.get(n);
  }
};

class RandomizedSet2 {
 public:
  /** Initialize your data structure here. */
  RandomizedSet2() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (m.find(val) != m.end()) return false;
    nums.emplace_back(val);
    m[val] = nums.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (m.find(val) == m.end()) return false;
    int last = nums.back();
    m[last] = m[val];
    nums[m[val]] = last;
    nums.pop_back();
    m.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return nums[rand() % nums.size()]; }

 private:
  vector<int> nums;
  unordered_map<int, int> m;
};
string bool_to_string(bool b) {
  if (b) return "true";
  return "false";
}
int test(vector<string>& functions, vector<vector<int>>& arguments) {
  cout << "Functions = ";
  Output::vectorPrint(functions);
  cout << endl;
  cout << "Arguments = ";
  Output::vectorPrint(arguments);
  cout << endl;
  string result = "Result (mine) = \n[";
  string result2 = "Result (optimal) = \n[";
  RandomizedSet r;
  RandomizedSet2 r2;
  for (int i = 0; i < functions.size(); i++) {
    if (functions[i] == "RandomizedSet") {
      r = RandomizedSet();
      result += "null";

      r2 = RandomizedSet2();
      result2 += "null";
    } else if (functions[i] == "insert") {
      bool inserted = r.insert(arguments[i][0]);
      result += bool_to_string(inserted);

      inserted = r2.insert(arguments[i][0]);
      result2 += bool_to_string(inserted);
    } else if (functions[i] == "remove") {
      bool removed = r.remove(arguments[i][0]);
      result += bool_to_string(removed);

      removed = r2.remove(arguments[i][0]);
      result2 += bool_to_string(removed);
    } else if (functions[i] == "getRandom") {
      int randomVal = r.getRandom();
      result += to_string(randomVal);

      randomVal = r2.getRandom();
      result2 += to_string(randomVal);
    }
    if (i != functions.size() - 1) {
      result += ",";
      result2 += ",";
    }
  }
  result += "]";
  result2 += "]";
  cout << result << endl;
  cout << result2 << endl;
  return 0;
}
int main() {
  try {
    vector<string> functions = {"RandomizedSet", "insert",    "remove",
                                "insert",        "getRandom", "remove",
                                "insert",        "getRandom"};
    vector<vector<int>> arguments = {{}, {1}, {2}, {2}, {}, {1}, {2}, {}};
    test(functions, arguments);
    functions = {"RandomizedSet", "insert", "insert",   "remove",
                 "insert",        "remove", "getRandom"};
    arguments = {{}, {0}, {1}, {0}, {2}, {1}, {}};
    test(functions, arguments);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}