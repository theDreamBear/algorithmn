/*
 * @lc app=leetcode.cn id=457 lang=cpp
 * @lcpr version=30204
 *
 * [457] 环形数组是否存在循环
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
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n);
        auto dfs = [&](auto&& dfs, int i, int fa)->bool {
            vis[i] = fa;
            int j = ((i + nums[i]) % n + n) % n;
            // 自环
            if (i == j) return false;
            // 如果不能保持同正负, 提前结束
            if (nums[i] * nums[j] < 0) {
                return false;
            }
            if (vis[j]) {
                // 是否是本次的节点
                return vis[j] == fa;
            }
            return dfs(dfs, j, fa);
        };
        for (int i = 0; i < n; i++) {
            if (!vis[i] and dfs(dfs, i, i + 1)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,-1,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3,-4,-5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,-1,5,1,4]\n
// @lcpr case=end

 */

