/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 * @lcpr version=30204
 *
 * [2698] 求一个整数的惩罚数
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
    // 纯暴力
    int punishmentNumber(int n) {
        int ans = 0;
        auto isOK = [](string& s, int target) {
            // 递归所有情况
            auto dfs = [&](auto&& dfs, int i, int v)->bool {
                if (i >= s.size()) {
                    return v == target;
                }
                if (v > target) {
                    return false;
                }
                int val = 0;
                for (int j = i; j < s.size(); j++) {
                    val = val * 10 + (s[j] - '0');
                    if (dfs(dfs, j + 1, v + val)) {
                        return true;
                    }
                }
                return false;
            };
            return dfs(dfs, 0, 0);
        };
        for (int i = 1; i <= n; i++) {
            int x = i * i;
            auto sx = to_string(x);
            if (isOK(sx, i)) {
                ans += x;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 37\n
// @lcpr case=end

 */

