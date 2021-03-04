/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
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
    int smallestRangeI1(vector<int>& A, int K) {
        auto mm = minmax_element(A.begin(), A.end());
        int diff = *mm.second - *mm.first;
        if (diff <= 2 * K) {
            return 0;
        }
        return diff - 2 * K;
    }

    pair<int, int> myMinMax(vector<int>& A) {
        int mm = INT_MAX, ma = INT_MIN, i = 0;
        if (A.size() % 2 != 0) {
            ++i;
            mm = A[0];
            ma = A[0];
        }
        while (i + 1 < A.size()) {
            auto dd = minmax(A[i], A[i + 1]);
            if (dd.second > ma) {
                ma = dd.second;
            }
            if (dd.first < mm) {
                mm = dd.first;
            }
            i += 2;
        }
        return {mm, ma};
    }

    int smallestRangeI(vector<int>& A, int K) {
        auto mm = myMinMax(A);
        int diff = mm.second - mm.first;
        if (diff <= 2 * K) {
            return 0;
        }
        return diff - 2 * K;
    }
};
// @lc code=end

