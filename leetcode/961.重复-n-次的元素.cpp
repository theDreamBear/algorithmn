/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 重复 N 次的元素
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
char ah[10000];
class Solution {
public:
    int repeatedNTimes_sort(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i - 1]) {
                return A[i];
            }
        }
        return 0;
    }
    int repeatedNTimes_map(vector<int>& A) {
        fill(begin(ah), end(ah), 0);
        for (int i = 0; i < A.size(); ++i) {
            if (++ah[A[i]] > 1) {
                return A[i];
            }
        }
        return 0;
    }

    int repeatedNTimes(vector<int>& A) {
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i - 1]) {
                return A[i];
            }
        }
        if (A[0] == A[2] || A[0] == A[3]) {
            return A[0];
        }
        return A[1];
    }
};
// @lc code=end

