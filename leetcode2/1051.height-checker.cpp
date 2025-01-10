/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 * @lcpr version=30204
 *
 * [1051] 高度检查器
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
    int heightChecker(vector<int>& heights) {
        auto x = heights;
        ranges::sort(x);
        int ans = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != heights[i]) ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

