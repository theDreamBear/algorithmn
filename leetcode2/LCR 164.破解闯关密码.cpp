/*
 * @lc app=leetcode.cn id=LCR 164 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 164] 破解闯关密码
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
    string crackPassword(vector<int>& password) {
        sort(password.begin(), password.end(), [&](int left, int right) {
            auto l = to_string(left);
            auto r = to_string(right);
            return l + r < r + l;
        });
        string ans;
        for (auto v : password) {
            ans += to_string(v);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [15, 8, 7]\n
// @lcpr case=end

// @lcpr case=start
// [0, 3, 30, 34, 5, 9]\n
// @lcpr case=end

 */

