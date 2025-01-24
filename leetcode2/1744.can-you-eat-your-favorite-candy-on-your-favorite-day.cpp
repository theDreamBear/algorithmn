/*
 * @lc app=leetcode.cn id=1744 lang=cpp
 * @lcpr version=30204
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
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
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + candiesCount[i - 1];
        int m = queries.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            int type = queries[i][0], day = queries[i][1], cap = queries[i][2];
            if (pre[type] < (long long)cap * (day + 1) and pre[type + 1] >= day + 1) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,4,5,3,8]\n[[0,2,2],[4,2,4],[2,13,1000000000]]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,6,4,1]\n[[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]\n
// @lcpr case=end

 */

