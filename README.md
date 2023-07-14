# leetcode

This repository contains problems I have completed on leetcode.

## Repo Structure

### Modules

Helpful functions and classes that can be re-used between programs.

### Template

Can be copied to quickly start on a new problem. Remember to change the copied folder name and README contents according to the problem-folder structure before working in `solution.cpp`.

### Problems

Each problem folder is named starting with the problem no left padded to make up 4 digits followed by the question title in lowercase using `-` in place of whitespaces.

The structure of each solved problem is as follows

- problem-folder
  - README.md
    - Problem Title
    - Leetcode URL
    - Question
    - [Solution Explanation?]
  - solution.cpp
    - class Solution - initial solution I come up with
    - class Optimal - optimal solution after optimizing my code and then checking solutions on leetcode
    - func test - test code in Solution and Optimal using timing functions from `modules/perf.h`
    - func main - test cases

Browsing through some problem folders will quickly show that the above structure is used mainly as a guideline and deviations from this structure do happen. Some examples of when this structure is broken is

1. Questions where argument is passed by reference and modified in the function. Couldn't figure out how to test such functions in a generic fashion, so either no testing or test() is written in a way specific to the problem.
2. Folders created prior to the development of the above structure.

## Problem Lists

### top-100-liked-questions

URL: <https://leetcode.com/problem-list/top-100-liked-questions/>

### top-145-interview-questions

URL: <https://leetcode.com/problem-list/top-interview-questions/>

### top-150-interview-questions-study-plan

Currently working on this.

URL: <https://leetcode.com/studyplan/top-interview-150/>

## Problems To Re-visit

- 1187-make-array-strictly-increasing
- 1569-number-of-ways-to-reorder-array-to-get-same-bst
- 2328-number-of-increasing-paths-in-a-grid
