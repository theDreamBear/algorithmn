/*
 * @lc app=leetcode.cn id=2457 lang=cpp
 * @lcpr version=30204
 *
 * [2457] 美丽整数的最小增量
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
    long long makeIntegerBeautiful(long long n, int target) {
        auto s = to_string(n);
        vector<int> pre(s.size() + 1);
        for (int i = 0; i < s.size(); i++) {
            pre[i + 1] = pre[i] + (s[i] - '0');
        }
        auto it = ranges::upper_bound(pre, target);
        if (it == pre.end()) {
            return 0;
        }
        long long val = 0;
        long long ma = 1;
        it = ranges::lower_bound(pre, target);
        if (it != pre.begin()) {
            int i = prev(it) - pre.begin();
            for (; i < s.size(); i++) {
                ma *= 10;
                val = val * 10 + s[i] - '0';
            }
        }
        return ma - val;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 16\n6\n
// @lcpr case=end

// @lcpr case=start
// 467\n6\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

