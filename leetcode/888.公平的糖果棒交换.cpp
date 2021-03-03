/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果棒交换
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include<numeric>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int left = accumulate(A.begin(), A.end(), 0);
        int right = accumulate(B.begin(), B.end(), 0);
        unordered_set<int> bhash(B.begin(), B.end());

        int diff = 0;
        diff = (left + right) / 2 - right;
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] - diff > 0 && bhash.count(A[i] - diff) > 0) {
                return {A[i], A[i] - diff};
            }
        }
        return {0, 0};
    }
};
// @lc code=end
