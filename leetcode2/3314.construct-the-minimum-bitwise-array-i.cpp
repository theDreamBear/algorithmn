/*
 * @lc app=leetcode.cn id=3314 lang=cpp
 * @lcpr version=30204
 *
 * [3314] 构造最小位运算数组 I
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
    vector<int> minBitwiseArray1(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= nums[i]; j++) {
                if (nums[i] == ((j + 1) | j)) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++) {
            // x | (x + 1) 只和第一个0有关系
            // 规则1 偶数没有结果
            // 规则2 置位全为1， 结果为一半，向下取整
            // 规则3 找到第一个0，其余位置置位0 错了
            if (nums[i] == 2) {
                continue;
            }
            // int x = ((nums[i] + 1) & nums[i]);
            // ans[i] = x + (nums[i] - x) / 2;
            //ans[i] = (((nums[i] + 1) ^ nums[i]) + 1) >> 2 ^ nums[i];
            ans[i] = nums[i] ^ (((nums[i] + 1) & ~nums[i]) >> 1);
        }
        return ans;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,31]\n
// @lcpr case=end

 */

