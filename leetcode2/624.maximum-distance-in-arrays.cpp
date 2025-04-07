/*
 * @lc app=leetcode.cn id=624 lang=cpp
 * @lcpr version=30204
 *
 * [624] 数组列表中的最大距离
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
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxDistance1(vector<vector<int>>& arrays) {
        multiset<int> sm, bi;
        for (auto& arr: arrays) {
            sm.insert(arr.front());
            bi.insert(arr.back());
        }
        int ans = 0;
        for (auto& arr: arrays) {
            int s = arr.front(), b = arr.back();
            bi.extract(b);
            ans = max(ans, abs(*bi.rbegin() - s));
            bi.insert(b);

            sm.extract(s);
            ans = max(ans, abs(b - *sm.begin()));
            sm.insert(s);
        }
        return ans;
    }

    int maxDistance(vector<vector<int>>& arrays) {
        int mx = INT_MIN / 2, mm = INT_MAX / 2;
        int ans = 0;
        for (auto& arr: arrays) {
            int s = arr.front(), b = arr.back();
            ans = max({ans, mx - s, b - mm});
            mx = max(mx, b);
            mm = min(mm, s);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5],[1,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[1]]\n
// @lcpr case=end

 */

