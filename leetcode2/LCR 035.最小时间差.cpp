/*
 * @lc app=leetcode.cn id=LCR 035 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 035] 最小时间差
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> ts(timePoints.size());
        for (int i = 0; i < timePoints.size(); i++) {
            ts[i] = atoi(timePoints[i].c_str()) * 60 + atoi(timePoints[i].c_str() + 3);
        }
        // 暴力解法
        // int ans = 24 * 60;
        // for (int i = 0; i < ts.size(); i++) {
        //     for (int j = i + 1; j < ts.size(); j++) {
        //         ans = min({ans, (ts[i] - ts[j] + 1440) % 1440, (ts[j] - ts[i] + 1440) % 1440});
        //     }
        // }
        //return ans;
        // 排序
        sort(ts.begin(), ts.end());
        int ans = min((ts[0] - ts.back() + 1440) % 1440, ts.back() - ts[0]);
        for (int i = 1; i < ts.size(); i++) {
            ans = min(ans, ts[i] - ts[i - 1]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["23:59","00:00"]\n
// @lcpr case=end

// @lcpr case=start
// ["00:00","23:59","00:00"]\n
// @lcpr case=end

 */

