#include "../modules/index.h"
#define ITERATIONS 1
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int threshold = nums.size() / 2;
    unordered_map<int, int> count;
    for (int num : nums) {
      if (count.find(num) == count.end()) {
        count[num] = 1;
      } else {
        count[num]++;
      }
      if (count[num] > threshold) {
        return num;
      }
    }
    return -1;
  }
};
class Optimal {
 public:
  int majorityElement(vector<int>& nums) {
    // Boyer–Moore majority vote algorithm
    // The algorithm chooses the first element in the sequence as the majority
    // candidate c and initializes a counter for that candidate with value 1. If
    // the candidate is not the majority element, then the counter must reach
    // zero since there are more elements in the sequence that are not equal to
    // the candidate. When the counter reaches zero after K < N iterations, then
    // we consumed exactly K / 2 elements with the candidate value (K must be
    // even). Whether the candidate equals to the majority element m or not, we
    // are left with a subsequence of length N - K where m is still the majority
    // element.

    int i, candidate = -1, votes = 0;
    int n = nums.size();
    for (i = 0; i < n; i++) {
      if (votes == 0) {
        candidate = nums[i];
        votes = 1;
      } else if (nums[i] == candidate) {
        votes++;
      } else {
        votes--;
      }
    }
    return candidate;

    // No need to verify candidate since
    // nums is guaranteed to have a majority element
    // int count = 0;
    // for (int num : nums) {
    //   if (num == candidate) count++;
    // }

    // if (count > nums.size() / 2) return candidate;
    // return -1;
  }
};
int test(vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nNums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(nums);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::majorityElement, s, nums);
  cout << "\tmajorityElement(mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::majorityElement, o, nums);
  cout << "\tmajorityElement(optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int getRandomInclusive(int min, int max) {
  return rand() % (max - min + 1) + min;
}
vector<int> generateRandomVector(int size) {
  // generate random vector with size
  // while ensuring that there is a majority element
  vector<int> x;
  int majority = getRandomInclusive(0, 100);
  int majorityCount = getRandomInclusive(size / 2 + 1, size * 0.75);
  int minorityCount = size - majorityCount;

  for (int i = 0; i < majorityCount; i++) {
    x.push_back(majority);
  }
  for (int i = 0; i < minorityCount; i++) {
    x.push_back(getRandomInclusive(0, 100));
  }
  random_shuffle(x.begin(), x.end());
  return x;
}
int main() {
  srand(time(NULL));
  vector<int> x = {3, 2, 3};
  test(x);
  x = {2, 2, 1, 1, 1, 2, 2};
  test(x);
  x = {1};
  test(x);
  x = generateRandomVector(1000);
  test(x);
  x = generateRandomVector(1000);
  test(x);
  x = generateRandomVector(1000);
  test(x);
  return 0;
}