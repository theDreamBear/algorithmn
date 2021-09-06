/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
 public:
    bool canH(const vector<int>& data, int h) {
        int ct = 0;
#ifdef VI
        for (int i = data.size() - 1; i >= 0; i--) {
            if (data[i] >= h) {
                ++ct;
            } else {
                return ct >= h;
            }
        }
        return true;
#else
        ct = data.size() + data.begin() - lower_bound(data.begin(), data.end(), h);
        return ct >= h;
#endif
    }


    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int high = min((int)citations.back(), (int)citations.size());
        int low = 0;
        while (low + 1 < high) {
            int mid = (high - low) / 2 + low;
            if (canH(citations, mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (canH(citations, high)) {
            return high;
        }
        return low;
    }
};
// @lc code=end

