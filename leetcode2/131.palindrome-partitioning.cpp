/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30204
 *
 * [131] 分割回文串
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
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> isP(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                bool is = true;
                for (int l = j, r = i; l < r and is; l++, r--) {
                    if (s[l] != s[r]) {
                        is = false;
                    }
                }
                isP[j][i] = is;
            }
        }
        // 回溯
        vector<vector<string>> ans;
        vector<string> cur;
        auto dfs = [&](auto&& dfs, int i) {
            if (i >= n) {
                ans.push_back(cur);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (isP[i][j]) {
                    cur.push_back(s.substr(i, j - i + 1));
                    dfs(dfs, j + 1);
                    cur.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

