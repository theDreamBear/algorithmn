/*
 * @lc app=leetcode.cn id=3176 lang=cpp
 * @lcpr version=30204
 *
 * [3176] 求出最长好子序列 I
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
    int maximumLength2(vector<int>& nums, int k) {
        // 最长不相等
        // cnt[i] 结尾的最大长度
        int ans = 1;
        int n = nums.size();
        int cnt[510][30]{};
        // cnt[i][j] i结尾且值j的最大长度
        for (int j = 0; j <= n; j++) {
            cnt[j][0] = 1;
        }
        // cnt[i][t] == 最大[t]
        //  !=  最大t - 1
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                for (int t = 0; t <= k; t++) {
                    if (nums[i] == nums[j]) {
                        cnt[i][t] = max(cnt[i][t], cnt[j][t] + 1);
                    } else if (t > 0) {
                        cnt[i][t] = max(cnt[i][t], cnt[j][t - 1] + 1);
                    }
                    ans = max(ans, cnt[i][t]);
                }
            }
        }
        return ans;
    }

    int maximumLength(vector<int>& nums, int k) {
        // 最长不相等
        // cnt[i] 结尾的最大长度
        int ans = 1;
        int n = nums.size();
        int cnt[510][30]{};
        // cnt[i][j] i结尾且值j的最大长度
        for (int j = 0; j <= n; j++) {
            cnt[j][0] = 1;
        }
        // cnt[i][t] == 最大[t]
        //  !=  最大t - 1
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                for (int t = 0; t <= k; t++) {
                    if (nums[i] == nums[j]) {
                        cnt[i][t] = max(cnt[i][t], cnt[j][t] + 1);
                    } else if (t > 0) {
                        cnt[i][t] = max(cnt[i][t], cnt[j][t - 1] + 1);
                    }
                    ans = max(ans, cnt[i][t]);
                }
            }
        }
        return ans;
    }


    int maximumLength1(vector<int>& nums, int k) {
        // 最长不相等
        // cnt[i] 结尾的最大长度
        int n = nums.size();
        int cnt[510][30]{};
        // cnt[i][j] i结尾且值最多为j的最大长度
        for (int j = 0; j <= k; j++) {
            cnt[0][j] = 1;
        }
        int ans = 1;
        for (int i = 1; i < n; i++) {
            cnt[i][0] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j]) {
                    cnt[i][0] = max(cnt[i][0], cnt[j][0] + 1);
                    ans = max(ans, cnt[i][0]);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // 枚举
                for (int t = 1; t <= k; t++) {
                    cnt[i][t] = max(cnt[i][t], cnt[i][t - 1]);
                    if (nums[i] == nums[j]) {
                        cnt[i][t] = max(cnt[i][t], cnt[j][t] + 1);
                    } else {
                        cnt[i][t] = max(cnt[i][t], cnt[j][t - 1] + 1);
                    }
                    ans = max(ans, cnt[i][t]);
                }
            }
        }
        return ans;
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

