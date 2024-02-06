/*
 * @lc app=leetcode.cn id=LCR 131 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 131] 砍竹子 I
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
    int cuttingBambooHelper(int bamboo_len, unordered_map<int, int>& memo) {
        if (bamboo_len <= 1) {
            return 1;
        }
        if (memo.count(bamboo_len)) {
            return memo[bamboo_len];
        }
        int ans = bamboo_len;
        for (int i = 1; i <= bamboo_len / 2; i++) {
            int val = cuttingBambooHelper(i, memo) * cuttingBambooHelper(bamboo_len - i, memo);
            ans = max(ans, val);
        }
        return memo[bamboo_len] = ans;
    }

    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len <= 1) {
            return 1;
        }
        int ans = 0;
        unordered_map<int, int> memo;
        for (int i = 1; i <= bamboo_len / 2; i++) {
            int val = cuttingBambooHelper(i, memo) * cuttingBambooHelper(bamboo_len - i, memo);
            ans = max(ans, val);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

 */

