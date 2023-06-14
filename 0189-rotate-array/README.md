# Rotate Array

URL: <https://leetcode.com/problems/rotate-array/>

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105

Follow up:

    Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
    Could you do it in-place with O(1) extra space?

n = 9

k = 3

n - k - 1 = 5

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   |
| 9   | 8   | 7   | 4   | 5   | 6   | 3   | 2   | 1   |
| 7   | 8   | 9   | 4   | 5   | 6   | 3   | 2   | 1   |
| 7   | 8   | 9   | 6   | 5   | 4   | 3   | 2   | 1   |
| 7   | 8   | 9   | 1   | 2   | 3   | 4   | 5   | 6   |

             k - 1                   n - k       n - 1

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | Action             |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | ------------------ |
| 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | reverse(0, n - 1)  |
| 9   | 8   | 7   | 6   | 5   | 4   | 3   | 2   | 1   | reverse(0, k - 1)  |
| 7   | 8   | 9   | 6   | 5   | 4   | 3   | 2   | 1   | reverse(k , n - 1) |
| 7   | 8   | 9   | 1   | 2   | 3   | 4   | 5   | 6   |
