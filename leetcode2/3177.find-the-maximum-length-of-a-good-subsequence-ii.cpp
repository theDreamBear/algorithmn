/*
 * @lc app=leetcode.cn id=3177 lang=cpp
 * @lcpr version=30204
 *
 * [3177] 求出最长好子序列 II
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
#include <map>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
//int cnt[10000][60]{};
class Solution {
public:
    int maximumLength1(vector<int>& nums, int k) {
        // 最长不相等
        // cnt[i] 结尾的最大长度
        int ans = 1;
        int n = nums.size();
        //             k,      len, value
        // value1, t 最大的
        // value2 t  次大的

        // value1 t - 1 最大的
        // value2 t - 1 次大的

        // cnt[i][t] == 最大[t]
        //  !=  最大t - 1

        // 找相同的最大值
        unordered_map<int, map<int, int>> cnt1;
        // 找不相同的最大值
        vector<array<int, 3>> pre(k + 1);
        for (int i = 0; i < n; i++) {
            for (int t = 0; t <= k; t++) {
                // 相同 + 1
                cnt1[nums[i]][t] += 1;
                if (t > 0) {
                    // 不相同最大
                    if (nums[i] == pre[t - 1][0]) {
                        cnt1[nums[i]][t] = max(cnt1[nums[i]][t], pre[t - 1][2] + 1);
                    } else {
                        cnt1[nums[i]][t] = max(cnt1[nums[i]][t], pre[t - 1][1] + 1);
                    }
                }
                if (cnt1[nums[i]][t] > pre[t][1]) {
                    if (nums[i] == pre[t][0]) {
                        pre[t][1] = cnt1[nums[i]][t];
                    } else {
                        pre[t][0] = nums[i];
                        pre[t][2] = pre[t][1];
                        pre[t][1] = cnt1[nums[i]][t];
                    }
                } else if (cnt1[nums[i]][t] > pre[t][2]) {
                    pre[t][2] = cnt1[nums[i]][t];
                }
                ans = max(ans, cnt1[nums[i]][t]);
            }
            // 更新
        }
        return ans;
    }

    int maximumLength(vector<int>& nums, int k) {
        // 最长不相等
        // cnt[i] 结尾的最大长度
        int ans = 1;
        int n = nums.size();
        //             k,      len, value
        // value1, t 最大的
        // value2 t  次大的

        // value1 t - 1 最大的
        // value2 t - 1 次大的

        // cnt[i][t] == 最大[t]
        //  !=  最大t - 1

        // 找相同的最大值
        unordered_map<int, vector<int>> cnt1;
        // 找不相同的最大值
        vector<int> pre(k + 2);
        for (auto x: nums) {
            auto& f = cnt1[x];
            f.resize(k + 1);
            for (int j = k; j >= 0; j--) {
                f[j] = max(f[j], pre[j]) + 1;
                pre[j + 1] = max(pre[j + 1], f[j]);
            }
        }
        return pre[k + 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,1]\n0\n
// @lcpr case=end

 */

