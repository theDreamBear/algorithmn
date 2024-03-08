/*
 * @lc app=leetcode.cn id=LCR 003 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 003] 比特位计数
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
    vector<int> countBits1(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i < n + 1; i++) {
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }

    int ct(int n) {
        int res = 0;
        while (n) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i < n + 1; i++) {
            ans[i] = ct(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

