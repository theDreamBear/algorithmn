/*
 * @lc app=leetcode.cn id=168 lang=cpp
 * @lcpr version=30204
 *
 * [168] Excel 表列名称
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
    string convertToTitle(int val) {
        string dict = "Z";
        for (char c = 'A'; c < 'Z'; c++) dict.push_back(c);
        string ans;
        while (val) {
            int x = val % 26;
            ans.push_back(dict[x]);
            if (x == 0) {
                val -= 26;
            }
            val /= 26;
        }
        ranges::reverse(ans);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 28\n
// @lcpr case=end

// @lcpr case=start
// 701\n
// @lcpr case=end

// @lcpr case=start
// 2147483647\n
// @lcpr case=end

 */

