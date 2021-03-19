/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_far = 0,  end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            max_far = max(max_far, i + nums[i]);
            if (i > max_far) {
                return false;
            }
            if (i == end) {
                end = max_far;
                if (end >= nums.size() - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

