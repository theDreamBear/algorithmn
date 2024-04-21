/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30122
 *
 * [216] 组合总和 III
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
    vector<vector<int>> combinationSum3(int k, int n) {
        int small = (1 + k) * k >> 1;
        if (small > n) {
            return {};
        }
        int big = (9 + 9 - k + 1) * k >> 1;
        if (big < n) {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int value, int left)> dfs = [&](int value, int left)->void {
            if (value > 9 || left < value || tmp.size() >= k) {
                if (left == 0 && tmp.size() == k) {
                    ans.push_back(tmp);
                }
                return;
            }
            int d = k - tmp.size();
            if (9 - value + 1 < d || (value + value + d - 1) / 2 > left) {
                return;
            }
            for (int v = value; v <= min(9, left); v++) {
                if (v > left) {
                    break;
                }
                tmp.push_back(v);
                dfs(v + 1, left - v);
                tmp.pop_back();
            }
        };
        dfs(1, n);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

