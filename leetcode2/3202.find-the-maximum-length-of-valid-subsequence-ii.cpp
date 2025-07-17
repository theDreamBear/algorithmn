/*
 * @lc app=leetcode.cn id=3202 lang=cpp
 * @lcpr version=30204
 *
 * [3202] 找出有效子序列的最大长度 II
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
    // 最暴力解法, 枚举第一个和第二个节点O(n^3)
    int maximumLength_brute(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int val = (nums[i] + nums[j]) % k;
                int len = 2;
                for (int idx = j, a = j + 1; a < n; a++) {
                    if ((nums[idx] + nums[a]) % k == val) {
                        len++;
                        idx = a;
                    }
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }

    // 对暴力解法优化
    // (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k
    // 拆解式子发现, 对每一项%k, 那么相隔1个单位的值是相同的
    // 如1 3 1 3 1 3 1
    // f[1][3] = f[3][1] + 1
    int maximumLength1(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<vector<int>> f(k, vector<int>(k));
        for (auto jv: nums) {
            jv %= k;
            for (int i = 0; i < k; i++) {
                f[i][jv] = f[jv][i] + 1;
                ans = max(ans, f[i][jv]);
            }
        }
        return ans;
    }

    int maximumLength(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for (int m = 0; m < k; m++) {
            vector<int> f(k);
            for (auto v: nums) {
                v %= k;
                f[v] = f[(m - v + k) % k] + 1;
                ans = max(ans, f[v]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,3,1,4]\n3\n
// @lcpr case=end

 */

