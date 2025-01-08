/*
 * @lc app=leetcode.cn id=面试题 08.03 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.03] 魔术索引
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
    // 不能二分
    int findMagicIndex1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums[i]) return i;
        }
        return -1;
    }

    int findMagicIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i) {
                return i;
            } else if (nums[i] > i) i = nums[i] - 1;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0, 2, 3, 4, 5]\n
// @lcpr case=end

// @lcpr case=start
// [1, 1, 1]\n
// @lcpr case=end

 */



