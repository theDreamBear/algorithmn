/*
 * @lc app=leetcode.cn id=2343 lang=cpp
 * @lcpr version=30204
 *
 * [2343] 裁剪数字后查询第 K 小的数字
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
    // 暴力枚举
    vector<int> smallestTrimmedNumbers1(vector<string>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = nums[0].size();
        vector<int> ans;
        for (auto& q: queries) {
            int rk = q[0], trim = q[1];
            vector<pair<string, int>> res;
            for (int i = 0; i < nums.size(); i++) {
                res.push_back({nums[i].substr(n - trim), i});
            }
            nth_element(res.begin(), res.begin() + rk - 1, res.end());
            ans.push_back(res[rk - 1].second);
        }
        return ans;
    }

     // 离线合并
    vector<int> smallestTrimmedNumbers2(vector<string>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = nums[0].size();
        unordered_map<int, vector<pair<int, int>>> q;
        for (int i = 0; i < m; i++) {
            q[queries[i][1]].push_back(make_pair(i, queries[i][0]));
        }
        vector<int> ans(m);
        for (auto& qk: q) {
            int trim = qk.first;
            vector<pair<string, int>> res;
            for (int i = 0; i < nums.size(); i++) {
                res.push_back({nums[i].substr(n - trim), i});
            }
            ranges::sort(res);
            for (auto& [i, rk]: qk.second) {
                ans[i] = res[rk - 1].second; 
            }
        }
        return ans;
    }

    // 基数排序
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> des(m + 1, vector<int>(n));
        ranges::iota(des[0], 0);
        for (int i = 1; i <= m; i++) {
            // 桶
            vector<int> B[10];
            for (auto v: des[i - 1]) {
                B[nums[v][m - i] - '0'].push_back(v);
            }
            // 按照桶收集
            int p = 0;
            for (int j = 0; j < 10; j++) {
                for (auto x: B[j]) {
                    des[i][p++] = x;
                }
            }
        }
        vector<int> ans;
        for (auto& q: queries) {
            ans.push_back(des[q[1]][q[0] - 1]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["102","473","251","814"]\n[[1,1],[2,3],[4,2],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// ["24","37","96","04"]\n[[2,1],[2,2]]\n
// @lcpr case=end

 */

