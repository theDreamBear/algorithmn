/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 * @lcpr version=30204
 *
 * [3211] 生成不含相邻零的二进制字符串
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
    vector<string> validStrings(int n) {
        vector<string> ans;
        auto dfs = [&](auto&& dfs, string& s) {
            if (s.size() >= n) {
                ans.push_back(s);
                return;
            }
            if (s.empty() || s.back() == '1') {
                s.push_back('0');
                dfs(dfs, s);
                s.pop_back();

                s.push_back('1');
                dfs(dfs, s);
                s.pop_back();
                return;
            }
            if (s.back() == '0') {
                s.push_back('1');
                dfs(dfs, s);
                s.pop_back();
            }
        };
        string s;
        dfs(dfs, s);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

