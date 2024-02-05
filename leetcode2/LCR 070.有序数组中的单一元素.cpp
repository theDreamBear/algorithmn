/*
 * @lc app=leetcode.cn id=LCR 070 lang=cpp
 * @lcpr version=30115
 *
 * [LCR 070] 有序数组中的单一元素
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
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for (auto v : nums) {
            ans ^= v;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,3,3,4,4,8,8]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,7,7,10,11,11]\n
// @lcpr case=end

 */

