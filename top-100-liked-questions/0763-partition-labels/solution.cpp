#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> partitionLabels(string s) {
    if (s.empty()) return vector<int>(0);
    vector<int> res;
    int i = 0, prev = -1;
    while (i < s.size()) {
      int last = s.find_last_of(s[i]);
      i++;
      while (i < last) {
        int temp = s.find_last_of(s[i]);
        if (temp > last) last = temp;
        i++;
      }
      if (last - prev <= 0) continue;
      res.push_back(last - prev);
      prev += last - prev;
    }
    return res;
  }
};
int main() {
  Solution* solution = new Solution();
  string s = "ababcbacadefegdehijhklij";
  cout << s << endl;
  vector<int> res = solution->partitionLabels(s);
  for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
    cout << *it << endl;
  }
  return 0;
}