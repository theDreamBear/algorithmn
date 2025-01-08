/*
 * @lc app=leetcode.cn id=面试题 17.10 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 17.10] 主要元素
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
    int majorityElement(vector<int>& nums) {
        int ct = 1, v = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == v) {
                ct++;
            } else if (--ct == 0) {
                ct = 1, v = nums[i];
            }
        }
        ct = 0;
        for (auto x: nums) ct += (x == v);
        if (ct * 2 > nums.size()) return v;
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5,9,5,9,5,5,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */

