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
    int smallestRangeI(vector<int>& A, int K) {
        auto mm = minmax_element(A.begin(), A.end());
        int diff = *mm.second - *mm.first;
        if (diff <= 2 * K) {
            return 0;
        }
        return diff - 2 * K;
    }
};
// @lc code=end

