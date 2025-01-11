/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 * @lcpr version=30204
 *
 * [1217] 玩筹码
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
    int minCostToMoveChips(vector<int>& position) {
        // ranges::sort(position);
        int n = position.size();
        int ma = INT_MAX;
        for (int p = 0; p < n; p++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ((position[p] - position[i]) & 1);
            }
            ma = min(ma, sum);
        }
        return ma;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1000000000]\n
// @lcpr case=end

 */

