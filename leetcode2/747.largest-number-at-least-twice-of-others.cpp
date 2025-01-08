/*
 * @lc app=leetcode.cn id=747 lang=cpp
 * @lcpr version=30204
 *
 * [747] 至少是其他数字两倍的最大数
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
    int dominantIndex1(vector<int>& nums) {
        if (nums.size() < 2) return -1;
        int big = -1, less = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (big == -1 or nums[i] > nums[big]) {
                swap(big, less);
                big = i;
            } else if (less == -1 or nums[i] > nums[less]) {
                less = i;
            }
        }
        if (nums[big] >= nums[less] * 2) return big;
        return -1;
    }

    int dominantIndex(vector<int>& nums) {
        if (nums.size() < 2) return -1;
        int m1 = -1, m2 = -1, idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > m1) {
                swap(m1, m2);
                idx = i;
                m1 = nums[i];
            } else if (nums[i] > m2) m2 = nums[i];
        }
        if (m1 >= m2 * 2) return idx;
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

