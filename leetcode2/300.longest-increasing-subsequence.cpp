/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30114
 *
 * [300] 最长递增子序列
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
private:
public:

    /**
     * @brief
     *
     * @param nums： 原始
     * @param cur： 当前使用的序列
     * @param i： 当前搜索的下标
     * @param len : 当前序列的长度
     * @return int： 整个搜索序列的最大长度
     * @note 时间复杂度会很大， 超时必然
     */
    int dfs(const vector<int>& nums, vector<int>& cur, int i, int len) {
        // 搜索到尽头
        if (i >= nums.size()) {
            return len;
        }
        // 至少大于当前的序列
        int max_len = len;
        auto it = lower_bound(cur.begin(), cur.begin() + len, nums[i]);
        if (it == cur.begin() + len) {
            auto tmp = cur[len];
            cur[len] = nums[i];
            max_len = max(max_len, dfs(nums, cur, i + 1, len + 1));
            cur[len] = tmp;
        } else if (*it > nums[i]) {
            auto tmp = *it;
            *it = nums[i];
            max_len = max(max_len, dfs(nums, cur, i + 1, it - cur.begin() + 1));
            *it = tmp;
        }
        return max_len = max(max_len, dfs(nums, cur, i + 1, len));
    }

    /*
        子序列的问题
        1、 获得所有子序列的算法
        2、 时刻保证子序列符合预期
        3、 怎么减枝
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cur(25001, -100000);
        return dfs(nums, cur, 0, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

