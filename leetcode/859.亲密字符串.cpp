/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
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
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (A == B) {
            vector<char> hash(26);
            for (int i = 0; i < A.size(); ++i) {   
                if (++hash[A[i] - 'a'] >= 2) {
                    return true;
                }
            }
            return false;
        }
        int l, r;
        int ct = 0;
        for (int i = 0; i < A.size() && ct <= 2; ++i) {
            if (A[i] != B[i]) {
                if (++ct == 1) {
                    l = i;
                } else {
                    r = i;
                }
            }
        }
        if (ct > 2 || ct == 1) {
            return false;
        } 
        return A[l] == B[r] && A[r] == B[l];
    }
};
// @lc code=end

