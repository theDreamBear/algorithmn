/*
 * @lc app=leetcode.cn id=598 lang=cpp
 * @lcpr version=30204
 *
 * [598] 区间加法 II
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mx = m, my = n;
        for (int i = 0; i < ops.size(); i++) {
            int x = ops[i][0], y = ops[i][1];
            mx = min(x, mx);
            my = min(y, my);
        }
        return mx * my;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[2,2],[3,3]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n[[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n[]\n
// @lcpr case=end

 */

