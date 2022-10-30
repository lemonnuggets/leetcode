#include "../modules/index.h"
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i1 = m - 1, i2 = n - 1;
    for (int i = n + m - 1; i >= 0; i--) {
      if ((i2 < 0) || (i1 >= 0 && nums1[i1] > nums2[i2])) {
        nums1[i] = nums1[i1];
        i1--;
      } else {
        nums1[i] = nums2[i2];
        i2--;
      }
    }
  }
};

int test(vector<int>& x, int m, vector<int>& y, int n) {
  Solution s = Solution();
  Timer t = Timer();
  int duration;

  cout << "\nX (m = " << m << ") = \t";
  Output::vector(x);
  cout << endl;
  cout << "Y (n = " << n << ") = \t";
  Output::vector(y);
  cout << endl;

  t.startClock();
  s.merge(x, m, y, n);
  duration = t.stopClock();

  cout << "\tMerged Array, X = \t";
  Output::vector(x);
  cout << "\t\t\t\tTime Taken: " << duration << endl;

  return 0;
}
int main() {
  vector<int> nums1, nums2;
  int m, n;

  m = 3;
  nums1 = {1, 2, 3, 0, 0, 0};
  n = 3;
  nums2 = {2, 5, 6};
  test(nums1, m, nums2, n);

  m = 1;
  nums1 = {1};
  n = 0;
  nums2 = {};
  test(nums1, m, nums2, n);

  m = 0;
  nums1 = {0};
  n = 1;
  nums2 = {1};
  test(nums1, m, nums2, n);
  return 0;
}