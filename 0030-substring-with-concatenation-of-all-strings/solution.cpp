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
  int indexOf(string s, int start, int end, vector<string>& words,
              int wordsAfter = 0) {
    if (end > s.size() || start < 0 || end - start != words[0].size() ||
        wordsAfter > words.size()) {
      return -1;
    }
    for (int i = wordsAfter; i < words.size(); i++) {
      bool areEqual = true;
      for (int j = start; j < end; j++) {
        if (words[i][j - start] != s[j]) {
          areEqual = false;
          break;
        }
      }
      if (areEqual) {
        return i;
      }
    }
    return -1;
  }
  pair<bool, int> isPermutation(string s, int start, int end,
                                vector<string>& words) {
    int n = s.size();
    int wordSize = words[0].size(), wordsSize = words.size();

    pair<bool, int> response;
    if (start < 0 || end > n) {
      response.first = false;
      response.second = -1;
      return response;
    }
    vector<int> wordCounts(wordsSize, 0);
    for (int i = start; i < end; i += wordSize) {
      int idx, after = 0;
      idx = this->indexOf(s, i, i + wordSize, words);
      do {
        if (idx < 0) {
          response.first = false;
          response.second = start + 1;
          return response;
        }
        if (wordCounts[idx] <= 0) {
          break;
        }
        after = idx + 1;
        idx = this->indexOf(s, i, i + wordSize, words, after);
      } while (true);
      wordCounts[idx]++;
    }
    response.first = true;
    response.second = start + 1;
    return response;
  }
  vector<int> findSubstring(string s, vector<string>& words) {
    int wordsSize = words.size(), sSize = s.size(), wordSize = words[0].size();
    int substrSize = wordsSize * wordSize;
    if (sSize < wordsSize * wordSize) {
      return {};
    }
    vector<int> res;
    int i = 0;
    while (i < sSize) {
      auto permResult = this->isPermutation(s, i, i + substrSize, words);
      if (permResult.first) {
        res.push_back(i);
      }
      if (permResult.second < 0) {
        i++;
      } else {
        i = permResult.second;
      }
    }
    return res;
  }
};
class Optimal {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    unordered_map<string, int> counts;
    for (string word : words) counts[word]++;

    int numWords = words.size(), strLen = s.size(), wordLen = words[0].size();
    for (int i = 0; i < strLen - numWords * wordLen + 1; i++) {
      unordered_map<string, int> seen;

      int j = 0;
      for (; j < numWords; j++) {
        string word = s.substr(i + j * wordLen, wordLen);

        if (counts.find(word) == counts.end()) {
          break;
        }

        seen[word]++;
        if (seen[word] > counts[word]) {
          break;
        }
      }
      if (j == numWords) {
        res.emplace_back(i);
      }
    }
    return res;
  }
};
int test(string argument, vector<string>& words) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nS (size = " << argument.size() << ") = \t";
  cout << argument << endl;
  cout << "Words (size = " << words.size() << ") = \t";
  if (words.size() < 100) {
    Output::vectorPrint(words);
  }
  cout << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::findSubstring,
                                         s, argument, words);
  cout << "\tfindSubstring (mine), result = \t\t";
  if (result.second.size() < 100) {
    Output::vectorPrint(result.second);
  }
  cout << "\n\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::findSubstring, o,
                                    argument, words);
  cout << "\tfindSubstring (optimal), result = \t";
  if (result.second.size() < 100) {
    Output::vectorPrint(result.second);
  }
  cout << "\n\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string s;
  vector<string> words;
  s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  words = {"fooo", "barr", "wing", "ding", "wing"};
  test(s, words);
  // s =
  // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  //     "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  //     "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  //     "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  //     "aaaaaaaaaaaaaaaaaaaaaaaa";
  // words = {"aa", "aa", "aa", "aa", "aa", "aa", "aa"};
  // test(s, words);
  s = "wordgoodgoodgoodbestword";
  words = {"word", "good", "best", "good"};
  test(s, words);
  s = "barfoofoobarthefoobarman";
  words = {"foo", "bar", "the"};
  test(s, words);
  s = "barfoothefoobarman";
  words = {"foo", "bar"};
  test(s, words);
  s = "wordgoodgoodgoodbestword";
  words = {"word", "good", "best", "word"};
  test(s, words);
  return 0;
}