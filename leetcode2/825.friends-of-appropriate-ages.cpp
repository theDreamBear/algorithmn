/*
 * @lc app=leetcode.cn id=825 lang=cpp
 * @lcpr version=30204
 *
 * [825] 适龄的朋友
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
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        // y > 0.5x + 7
        // y <= x
        // y <= 100 and x >= 100
        // 枚举x 找y
        ranges::sort(ages);
        for (int i = 0; i < ages.size(); i++) {
            int y = ages[i] / 2 + 7 + 1;
            auto beg = ranges::lower_bound(ages, y) - ages.begin();
            auto end = --ranges::upper_bound(ages, ages[i]) - ages.begin();
            if (ages[i] >= 100) {
                auto ni = ranges::upper_bound(ages, 100);
                if (ni != ages.begin()) {
                    ni--;
                    auto en = ni - ages.begin();
                    en = min(end, en);
                    if (ages[i] == ages[en]) {
                        en--;
                    }
                    ans += max(0l, end - beg + 1);
                }
            } else {
                ans += (end - beg);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [16,16]\n
// @lcpr case=end

// @lcpr case=start
// [16,17,18]\n
// @lcpr case=end

// @lcpr case=start
// [20,30,100,110,120]\n
// @lcpr case=end

 */

