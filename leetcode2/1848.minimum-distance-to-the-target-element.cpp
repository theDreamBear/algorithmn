/*
 * @lc app=leetcode.cn id=1848 lang=cpp
 * @lcpr version=30204
 *
 * [1848] 到目标元素的最小距离
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
    int getMinDistance(vector<int>& nums, int target, int start) {
        for (int i = start, j = start; i >= 0 or j < nums.size(); i--, j++) {
            if ((i >= 0 and nums[i] == target) or (j < nums.size() and nums[j] == target)) return j - start;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n5\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1,1,1,1,1,1,1]\n1\n0\n
// @lcpr case=end

 */

