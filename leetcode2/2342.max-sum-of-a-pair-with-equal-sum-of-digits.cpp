/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 * @lcpr version=30204
 *
 * [2342] 数位和相等数对的最大和
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
    int maximumSum(vector<int>& nums) {
        //map<int, int> mv;
        int mv[82]{}; // 至多 9 个 9 相加
        int ans = -1;
        for (auto v: nums) {
            int ma = 0;
            for (int x = v; x; x/=10) ma+=x %10;
            if (mv[ma]) {
                ans = max(ans, v + mv[ma]);
            }
            mv[ma] = max(mv[ma], v);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [18,43,36,13,7]\n
// @lcpr case=end

// @lcpr case=start
// [10,12,19,14]\n
// @lcpr case=end

 */

