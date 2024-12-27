/*
 * @lc app=leetcode.cn id=3046 lang=cpp
 * @lcpr version=30204
 *
 * [3046] 分割数组
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
    bool isPossibleToSplit(vector<int>& nums) {
        int cnt[200]{};
        for (auto& x: nums) {
            if (++cnt[x] > 2) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */

