/*
 * @lc app=leetcode.cn id=2712 lang=cpp
 * @lcpr version=30204
 *
 * [2712] 使所有字符相等的最小成本
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
    long long minimumCost(string s) {
        unordered_map<int, int> advance, back;
        // 分组循环
        for (int i = 0; i < s.size(); ) {
            int start = i++;
            while (i < s.size() and s[start] == s[i]) i++;
            advance[start] = i;
        }
        for (int i = s.size() - 1; i >= 0;) {
            int start = i--;
            while (i >= 0 and s[start] == s[i]) i--;
            back[start] = i;
        }
        auto cal = [&](char target) {
            long long ans = 0;
            vector<vector<int>> left(s.size(), vector<int>(2, INT_MIN));
            auto dfs = [&](auto&& dfs ,int i, int j) {
                if (i < 0) return 0;

            }
            
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "0011"\n
// @lcpr case=end

// @lcpr case=start
// "010101"\n
// @lcpr case=end

 */

