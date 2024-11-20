/*
 * @lc app=leetcode.cn id=1561 lang=cpp
 * @lcpr version=30204
 *
 * [1561] 你可以获得的最大硬币数目
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
    int maxCoins(vector<int>& piles) {
        ranges::sort(piles);
        int ans = 0;
        int left = 0, right = piles.size() - 1;
        while (left + 1 < right) {
            ans += piles[right - 1];
            left++;
            right -= 2;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,1,2,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [9,8,7,6,5,1,2,3,4]\n
// @lcpr case=end

 */

