/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
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
    int jump1(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int nxt = 0, maxjump = 0;
        for (int i = 0; i + 1 < n; i++) {
            nxt = max(nxt, i + nums[i]);
            if (i == maxjump) {
                ans++;
                maxjump = nxt;
            }
        }
        return ans;
    }

    int jump2(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, INT_MAX);
        f[0] = 0;
        // 刷表法
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (f[i] != INT_MAX) {
                for (int j = i + 1; j <= min(n - 1, i + nums[i]); j++) {
                    f[j] = min(f[j], f[i] + 1);
                }
            }
        }
        return f[n - 1];
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, INT_MAX);
        f[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            // 
        }
        return f[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

