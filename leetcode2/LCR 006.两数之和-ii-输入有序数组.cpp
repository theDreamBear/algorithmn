/*
 * @lc app=leetcode.cn id=LCR 006 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 006] 两数之和 II - 输入有序数组
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
    vector<int> twoSum1(vector<int>& numbers, int target) {
        // 两根指针
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            // > target;
            while (left < right and numbers[left] + numbers[right] > target) {
                --right;
            }
            if (left >= right) {
                return {-1, -1};
            }
            if (numbers[left] + numbers[right] == target) {
                break;
            }
            while (left < right and numbers[left] + numbers[right] < target) {
                ++left;
            }
            if (left >= right) {
                return {-1, -1};
            }
            if (numbers[left] + numbers[right] == target) {
                break;
            }
        }
        return {left, right};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        // 两根指针
        int left = 0, right = numbers.size() - 1;
        for (; left < right;) {
            if (numbers[left] + numbers[right] > target) {
                --right;
            } else if (numbers[left] + numbers[right] == target) {
                break;
            } else {
                ++left;
            }
        }
        return {left, right};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,6,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */

