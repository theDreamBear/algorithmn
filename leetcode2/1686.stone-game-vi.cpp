/*
 * @lc app=leetcode.cn id=1686 lang=cpp
 * @lcpr version=30204
 *
 * [1686] 石子游戏 VI
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
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        int tb = 0;
        for (int i = 0 ; i < n; i++) {
            aliceValues[i] += bobValues[i];
            tb += bobValues[i];
        }
        ranges::sort(aliceValues, greater<>{});
        int ta = 0;
        for (int i = 0; i < n; i+=2) {
            ta += aliceValues[i];
        }
        int res = ta - tb;
        return (res > 0) - (res < 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[1,6,7]\n
// @lcpr case=end

 */

