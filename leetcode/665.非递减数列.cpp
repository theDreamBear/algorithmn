/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    bool checkPossibility(vector<int>& nums) {
        int bt = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            // 递减
            if (nums[i] > nums[i + 1]) {
                ++bt;
                if (i == 0) {
                    nums[i] = nums[i + 1];
                } else {
                    if (nums[i + 1] >= nums[i - 1]) {
                        nums[i] = nums[i + 1];
                    } else {
                        nums[i + 1] = nums[i];
                    }
                }
                if (bt > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main() { vector<int> nums = {4, 2, 1}; }
