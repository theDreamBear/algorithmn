/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30204
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ranges::sort(g);
        ranges::sort(s);
        int j = 0;
        int i = 0;
        for (; i < g.size() and j < s.size(); i++, j++) {
            while (j < s.size() and s[j] < g[i]) j++;
            // 找不到
            if (j >= s.size()) {
                break;
            }
        }
        return i;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */

