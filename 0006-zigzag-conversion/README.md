# Zigzag Conversion

URL: <https://leetcode.com/problems/zigzag-conversion/>

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```txt
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

```txt
P     I    N
A   L S  I G
Y A   H R
P     I
```

Example 3:

Input: s = "A", numRows = 1
Output: "A"

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

## Solution

Example

```txt
s = PAYPALISHIRING
numRows = 3
```

```txt
P     I    N
A   L S  I G
Y A   H R
P     I
```

Replacing characters with indices to simplify reasoning

```txt
Row0: 0     6       12
Row1: 1   5 7   11  13
Row2: 2 4   8 10
Row3: 3     9
      ^     ^       ^
      FCol  FCol    FCol
```

Here we can notice that difference between the indices in the same row for adjacent full columns (FCol) is 6 (eg. 0-6, 1-7, 2-8).
This can be explained once two observations are made:

1. Difference between indices in the same row for adjacent FCol will remain constant for each row in the FCol.
   Let this be referred to as `totalJump` as it represents the jump between two FCol.
2. When looking at the number of increments between the highest and lowest element in an FCol we notice that the number of increments
   is equal to numRows - 1. To get from this element to the highest element of next FCol there are numRows - 1 increments again.
   Therefore `totalJump = 2 * (numRows - 1)`

Right now if we constructed a string using increments of `totalJump` we notice that we will miss out the elements in between FCol.
Except the first and last row, there will be an element between elements in adjacent FCol. Let's refer to `jump1` as this difference
between this middle element and the FCol before it and `jump2` to refer to the difference between the middle element and the FCol after
it. Given this it is clear that `jump1 + jump2 = totalJump`

It can be observed that `jump1` decreases by 2 each time we go down a row and `jump2` increases by 2 each time we go down a row.
This can be explained due to the fact that every time we go down a row, the length of the path from element in first FCol to
middle element decreases by 2.

```txt
Row1: 5 - 1 = 4
1   5
2 4
3

1 -> 2 -> 3 -> 4 -> 5

Row2: 4 - 2 = 2
2 4
3

2 -> 3 -> 4
```

Here each `->` in the path is an increment. When we go from checking `jump1` in row 1 to that of row 2, we realize that the increment we counted
for `1->2` and `4->5` are not counted anymore so `jump1` reduces by 2.

We also realize that in Row0 `jump1 = totalJump` and `jump2 = 0` while in the last row `jump1 = 0` and `jump2 = totalJump`.

From the above observations we can generalize and say that `jump2 = 2 * row` and `jump1 = totalJump - jump2 = 2 * (numRows - row - 1)`.

Therefore we can get the indices for each row by first incrementing by `jump1` and then `jump2`. Terminate when generated index is greater than
size of string we are looking at. Repeat this for each row.
