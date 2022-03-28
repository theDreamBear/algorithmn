/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
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
    int removeElement(vector<int> &nums, int val) {
        int lastValIndex = nums.size() - 1;
        int ans = nums.size();
        while (lastValIndex >= 0 && nums[lastValIndex] == val) {
            --lastValIndex;
            --ans;
        }
        for (int i = 0; i < lastValIndex; i++) {
            if (nums[i] != val) {
                continue;
            }
            --ans;
            if (lastValIndex > i) {
                swap(nums[i], nums[lastValIndex]);
                --lastValIndex;
            }
            while (lastValIndex >= 0 && nums[lastValIndex] == val) {
                --lastValIndex;
                --ans;
            }
        }
        return ans;
    }
};
// @lc code=end
