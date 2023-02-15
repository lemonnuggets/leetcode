#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  template <typename T>
  int indexOf(vector<T> v, T x) {
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == x) return i;
    }
    return -1;
  }
  vector<string> generateParenthesis(int n) {
    if (n <= 0) return vector<string>(0);
    vector<string> res;
    if (n == 1) {
      res.push_back("()");
      return res;
    }
    vector<string> partialRes = generateParenthesis(n - 1);
    for (int i = 0; i < partialRes.size(); i++) {
      const string currentPartial = partialRes[i];
      for (int j = 1; j < currentPartial.size(); j++) {
        if (currentPartial[j] != ')') continue;
        const string before = currentPartial.substr(0, j);
        const string after = currentPartial.substr(j + 1);
        const string prepended = before + "())" + after;
        const string appended = before + ")()" + after;
        if (this->indexOf(res, prepended) == -1) res.push_back(prepended);
        if (this->indexOf(res, appended) == -1) res.push_back(appended);
      }
    }
    return res;
  }
};
int main() {
  Solution* solution = new Solution();
  int n = 8;
  cout << n << endl;
  vector<string> res = solution->generateParenthesis(n);
  cout << endl;
  for (auto it = res.begin(); it != res.end(); it++) {
    cout << *it << endl;
  }
  cout << res.size() << endl;
  return 0;
}