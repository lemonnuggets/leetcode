# Substring Template

```cpp
int findSubstring(string s) {
  vector<int> map(128, 0);
  int counter;             // check whether the substring is valid
  int begin = 0, end = 0;  // two pointers, one point to tail and one  minStart
  int reqdLen;             // the length of substring

  for () { /* initialize the hash map here */
  }

  while (end < s.size()) {
    if(map[s[end++]]-- ?){  /* modify counter here */
    }

    while (/* counter condition */) {
      /* update reqdLen here if finding minimum*/

      // increase begin to make it invalid/valid again

        if(map[s[begin++]]++ ?){ /*modify counter here*/
        }
    }

    /* update reqdLen here if finding maximum*/
  }
  return reqdLen;
}
```

## Examples

### 0003-longest-substring-without-repeating-characters

```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> map(128,0);
    int counter=0, begin=0, end=0, maxLen=0;
    while(end<s.size()){
        if(map[s[end++]]++>0) counter++;
        while(counter>0) if(map[s[begin++]]-- > 1) counter--;
        maxLen=max(maxLen, end-begin); //while valid, update maxLen
    }
    return maxLen;
}
```

### 0076-minimum-window-substring

```cpp
string minWindow(string s, string t) {
    vector<int> map(128,0);
    for(auto c: t) map[c]++;
    int counter=t.size(), begin=0, end=0, minLen=INT_MAX, minStart=0;
    while(end<s.size()){
        if(map[s[end++]]-- >0) counter--; //in t
        while(counter==0){ //valid
            if(end-begin<minLen)  {
              minStart=begin;
              minLen=end - begin;
            }
            if(map[s[begin++]]++==0) counter++;  //make it invalid
        }
    }
    return minLen==INT_MAX? "":s.substr(minStart, minLen);
}
```
