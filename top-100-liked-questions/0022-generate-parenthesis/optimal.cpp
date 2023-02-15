#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void iterate(const std::string& text, int open, int left,
               vector<string>& cache) {
    if (left == 0) {
      cache.push_back(text);
      return;
    }

    if (left == 1) {
      iterate(text + ")", open, left - 1, cache);
      return;
    }

    if (left - open > 0) {
      iterate(text + "(", open + 1, left - 1, cache);
    }

    if (open > 0) {
      iterate(text + ")", open - 1, left - 1, cache);
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> out;

    iterate("", 0, n * 2, out);

    return out;
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