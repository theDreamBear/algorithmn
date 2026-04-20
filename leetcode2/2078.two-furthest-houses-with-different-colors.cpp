/*
 * @lc app=leetcode.cn id=2078 lang=cpp
 * @lcpr version=30204
 *
 * [2078] 两栋颜色不同且距离最远的房子
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
    int maxDistance(vector<int>& colors) {
        vector<int> mm(101, INT_MAX);
        int ans = 0;
        for (int i = 0; i < colors.size(); i++) {
            for (int j = 0; j <= 100; j++) {
                if (j == colors[i] or mm[j] == INT_MAX) continue;
                ans = max(ans, i - mm[j]);
            }
            if (mm[colors[i]] == INT_MAX) mm[colors[i]] = i;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,6,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,8,3,8,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

 */

