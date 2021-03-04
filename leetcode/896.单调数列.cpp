/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isMonotonic1(vector<int>& A) {
        if (A.size() <= 1) {
            return true;
        }
        int flag = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] - A[i - 1] != 0) {
                if (flag == 0) {
                    flag = A[i] - A[i - 1];
                } else {
                    if (flag * (A[i] - A[i - 1]) < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isMonotonicHeler(const vector<int>& A, function<bool(int, int)> op) {
        for (int i = 1; i < A.size(); ++i) {
            bool cmp = op(A[i], A[i - 1]);
            if (!cmp) {
                return false;
            }

        }
        return true;
    }

    bool isMonotonic2(vector<int>& A) {
        if (A.size() <= 1) {
            return true;
        }
        if (isMonotonicHeler(A, less_equal<int>()) || isMonotonicHeler(A, greater_equal<int>())) {
            return true;
        }
        return false;
    }

    bool isMonotonic(vector<int>& A) {
        return is_sorted(A.begin(), A.end()) | is_sorted(A.rbegin(), A.rend());
    }
};
// @lc code=end

