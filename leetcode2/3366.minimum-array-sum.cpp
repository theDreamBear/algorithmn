/*
 * @lc app=leetcode.cn id=3366 lang=cpp
 * @lcpr version=30204
 *
 * [3366] 最小数组和
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
int f[200][200][200];
class Solution {
public:
    // f[100][101][101]
    int minArraySum1(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        memset(f, -1, sizeof f);
        auto dfs = [&](auto&& dfs, int i, int lop1, int lop2) {
            if (i >= n) return 0;
            auto& ans = f[i][lop1][lop2];
            if (ans != -1) return ans;
            // 不使用任何操作
            ans = dfs(dfs, i + 1, lop1, lop2);
            // i 使用操作1
            if (lop1 > 0) {
                // 使用操作1
                ans = max(ans, dfs(dfs, i + 1, lop1 - 1, lop2) + nums[i] / 2);
                // 使用操作1 同时 2
                if ((nums[i] + 1) / 2 >= k and lop2 > 0) {
                    ans = max(ans, dfs(dfs, i + 1, lop1 - 1, lop2 - 1) + nums[i] / 2 + k);
                }
            }
            // i 使用操作二
            if (lop2 > 0 and nums[i] >= k) {
                // 使用操作2
                ans = max(ans, dfs(dfs, i + 1, lop1, lop2 - 1) + k);
                // 使用操作二 然后操作一
                if (lop1 > 0) ans = max(ans, dfs(dfs, i + 1, lop1 - 1, lop2 - 1) + k + (nums[i] - k) / 2);
            }
            return ans;
        };
        return reduce(nums.begin(), nums.end(), 0) - dfs(dfs, 0, op1, op2);
    }

    int minArraySum2(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        memset(f, 0, sizeof f);
        // 递推
        for (int i = n - 1; i >= 0; i--) {
            for (int a = op1; a >= 0; a--) {
                for (int b = op2; b >= 0; b--) {
                    auto& res = f[i][a][b];
                    res = f[i + 1][a][b];
                    if (a > 0) {
                        res = max(res, f[i + 1][a - 1][b] + nums[i] / 2);
                        if ((nums[i] + 1) / 2 >= k and b > 0) {
                            res = max(res, f[i + 1][a - 1][b - 1] + nums[i] / 2 + k);
                        }
                    }
                    if (b > 0 and nums[i] >= k) {
                        res = max(res, f[i + 1][a][b - 1] + k);
                        if (a > 0) {
                            res = max(res, f[i + 1][a - 1][b - 1] + k + (nums[i] - k) / 2);
                        }
                    }
                }
            }
        }
        return reduce(nums.begin(), nums.end(), 0) - f[0][op1][op2];
    }

    int minArraySum3(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        memset(f, 0, sizeof f);
        // 递推
        // 滚动
        int ft = 0, st = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int a = op1; a >= 0; a--) {
                for (int b = op2; b >= 0; b--) {
                    int res = f[ft][a][b];
                    if (a > 0) {
                        res = max(res, f[ft][a - 1][b] + nums[i] / 2);
                        if ((nums[i] + 1) / 2 >= k and b > 0) {
                            res = max(res, f[ft][a - 1][b - 1] + nums[i] / 2 + k);
                        }
                    }
                    if (b > 0 and nums[i] >= k) {
                        res = max(res, f[ft][a][b - 1] + k);
                        if (a > 0) {
                            res = max(res, f[ft][a - 1][b - 1] + k + (nums[i] - k) / 2);
                        }
                    }
                    f[st][a][b] = res;
                }
            }
            swap(st, ft);
        }
        return reduce(nums.begin(), nums.end(), 0) - f[ft][op1][op2];
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        ranges::sort(nums);
        // [0, k - 1], // [k, 2k - 2], [2k - 1, +OO]
        auto it = ranges::lower_bound(nums, 2 * k - 1) - nums.begin();
        auto lit = ranges::lower_bound(nums, k) - nums.begin();
        for (int i = n - 1; i >= it; i--) {
            if (op1) {
                nums[i] = (nums[i] + 1) / 2;
                op1--;
            }
            if (op2) {
                nums[i] -= k;
                op2--;
            }
        }
        unordered_multiset<int> st;
        int odd = 0;
        for (int i = lit; i < it; i++) {
            if (op2) {
                nums[i] -= k;
                if (k % 2 and nums[i] % 2) {
                    st.insert(nums[i]);
                }
                op2--;
            } else {
                odd += nums[i] % 2;
            }
        }
        sort(nums.begin(), nums.begin() + it);
        int ans = 0;
        if (k % 2) {
            for (int i = it - op1; i < it and odd; i++) {
                int x = nums[i];
                auto it = st.find(x);
                if (it != st.end()) {
                    st.erase(it);
                    odd--;
                    ans--;
                }
            }
        }
        for (int i = it - 1; i >= 0 and op1; i--) {
            nums[i] = (nums[i] + 1) / 2;
            op1--;
        }
        return ans + reduce(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,8,3,19,3]\n3\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n3\n2\n1\n
// @lcpr case=end

 */

