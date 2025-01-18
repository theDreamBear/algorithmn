/*
 * @lc app=leetcode.cn id=3287 lang=cpp
 * @lcpr version=30204
 *
 * [3287] 求出数组中最大序列值
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
    int maxValue(vector<int>& nums, int k) {
        // 两部分的 or 值的 xor
        // 1. 不能排序
        // i 为右分界点
        int n = nums.size();
        auto find = [&](const vector<int>& vals, int k)->vector<unordered_set<int>> {
            vector<unordered_set<int>> dp;
            vector<unordered_set<int>> pre(k + 1);
            pre[0].insert(0);
            // 前i个
            for (int i = 0; i < vals.size(); i++) {
                // 更新
                for (int j = min(k - 1, i); j >= 0; j--) {
                    for (auto x: pre[j]) {
                        pre[j + 1].insert(x | vals[i]);
                    }
                }
                dp.push_back(pre[k]);
            }
            return dp;
        };
        auto pa = find(nums, k);
        auto pb = find(vector<int>(nums.rbegin(), nums.rend()), k);
        int mx = 0;
        // [0, x - 1], [x, n - 1]
        for (int x = k; x + k <= nums.size(); x++) {
            for (int a: pa[x - 1]) {
                for (int b: pb[n - x - 1]) {
                    mx = max(mx, a ^ b);
                }
            }
        }
        return mx;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,6,7]\n1\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5,6,7]\n2\n
// @lcpr case=end

 */

