#include "../modules/index.h"
#define ITERATIONS 50
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
const char SPACE = '-';
class Solution {
 public:
  string justifiedString(vector<string>& words, int start, int numWords,
                         int lineLength, int maxWidth) {
    string res = "";
    int remainingSpaces = maxWidth - lineLength;
    int remainingWords = numWords;
    int spaces;
    while (remainingWords > 1) {
      if (remainingSpaces % (remainingWords - 1) == 0) {
        spaces = remainingSpaces / (remainingWords - 1);
      } else {
        spaces = 1 + (remainingSpaces / (remainingWords - 1));
      }
      remainingSpaces -= spaces;
      res += words[start + (numWords - remainingWords)] + string(spaces, SPACE);
      remainingWords--;
    }
    res += words[start + numWords - 1];
    res += string(remainingSpaces, SPACE);
    return res;
  }
  string leftAlignedString(vector<string>& words, int start, int numWords,
                           int maxWidth) {
    string res = "";
    for (int i = start; i < start + numWords; i++) {
      res += words[i] + string(1, SPACE);
    }
    int n = res.size();
    if (n < maxWidth) {
      res += string(maxWidth - n, SPACE);
    } else if (n > maxWidth) {
      res.resize(maxWidth);
    }
    return res;
  }
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    vector<string> res;
    int firstWord = 0, numWordsInLine = 0, lineLength = 0;
    for (auto word : words) {
      int wLen = word.size();
      if (lineLength == 0) {
        numWordsInLine++;
        lineLength += wLen;
        continue;
      }
      if (lineLength + wLen + 1 <= maxWidth) {
        numWordsInLine++;
        lineLength += wLen + 1;
        continue;
      }
      lineLength -= numWordsInLine - 1;
      res.push_back(justifiedString(words, firstWord, numWordsInLine,
                                    lineLength, maxWidth));
      firstWord += numWordsInLine;
      numWordsInLine = 1;
      lineLength = word.size();
    }
    if (numWordsInLine > 0) {
      lineLength -= numWordsInLine - 1;
      res.push_back(
          leftAlignedString(words, firstWord, numWordsInLine, maxWidth));
      firstWord += numWordsInLine;
      numWordsInLine = 0;
      lineLength = 0;
    }
    return res;
  }
};
class Optimal {
 public:
  string justifiedString(vector<string>& words, int start, int numWords,
                         int lineLength, int maxWidth) {
    string res = "";
    int remainingSpaces = maxWidth - lineLength;
    int remainingWords = numWords;
    while (remainingWords > 1) {
      int spaces = ceil(remainingSpaces / (remainingWords - 1));
      remainingSpaces -= spaces;
      res += words[start + (numWords - remainingWords)] + string(spaces, SPACE);
      remainingWords--;
    }
    res += words[start + numWords - 1];
    res += string(remainingSpaces, SPACE);
    return res;
  }
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    vector<string> res;
    int firstWord = 0, numWordsInLine = 0, lineLength = 0;
    for (auto word : words) {
      int wLen = word.size();
      if (lineLength == 0) {
        numWordsInLine++;
        lineLength += wLen;
        continue;
      }
      if (lineLength + wLen + 1 <= maxWidth) {
        numWordsInLine++;
        lineLength += wLen + 1;
        continue;
      }
      lineLength -= numWordsInLine - 1;
      res.push_back(justifiedString(words, firstWord, numWordsInLine,
                                    lineLength, maxWidth));
      firstWord += numWordsInLine;
      numWordsInLine = 1;
      lineLength = word.size();
    }
    if (numWordsInLine > 0) {
      lineLength -= numWordsInLine - 1;
      res.push_back(justifiedString(words, firstWord, numWordsInLine,
                                    lineLength, maxWidth));
      firstWord += numWordsInLine;
      numWordsInLine = 0;
      lineLength = 0;
    }
    return res;
  }
};
int test(vector<string>& argument, int maxWidth) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nArgument (size = " << argument.size() << ") = \t";
  if (argument.size() < 100) {
    Output::vectorPrint(argument);
  }
  cout << "\nmaxWidth = " << maxWidth << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::fullJustify, s,
                                         argument, maxWidth);
  cout << "\tfullJustify (mine), result = \t\t";
  if (result.second.size() < 100) {
    Output::vectorPrint(result.second);
  }
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::fullJustify, o,
                                    argument, maxWidth);
  cout << "\tfullJustify (optimal), result = \t";
  if (result.second.size() < 100) {
    Output::vectorPrint(result.second);
  }
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<string> v;
  int maxWidth;
  v = {"ask", "not",  "what", "your", "country", "can", "do",   "for",    "you",
       "ask", "what", "you",  "can",  "do",      "for", "your", "country"};
  maxWidth = 16;
  test(v, maxWidth);
  v = {"This", "is", "an", "example", "of", "text", "justification."};
  maxWidth = 16;
  test(v, maxWidth);
  v = {"What", "must", "be", "acknowledgment", "shall", "be"};
  maxWidth = 16;
  test(v, maxWidth);
  v = {"Science", "is", "what",       "we",   "understand", "well",
       "enough",  "to", "explain",    "to",   "a",          "computer.",
       "Art",     "is", "everything", "else", "we",         "do"};
  maxWidth = 20;
  test(v, maxWidth);
  return 0;
}