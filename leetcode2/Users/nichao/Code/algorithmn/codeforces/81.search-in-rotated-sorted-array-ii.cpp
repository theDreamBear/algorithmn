/*
 * @lc app=leetcode.cn id=81 lang=cpp
 * @lcpr version=30204
 *
 * [81] 搜索旋转排序数组 II
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (nums[low] == nums[mid]) {
                if (nums[low] == target) return true;
                low++;
                continue;
            }
            if (nums[mid] < nums[low]) {
                if (nums[mid] <= target and nums[high] >= target) {
                    low = mid;
                } else {
                    high = mid;
                }
            } else {
                if (nums[mid] >= target and nums[low] <= target) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
        }
        return nums[low] == target or nums[high] == target;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,6,0,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,5,6,0,0,1,2]\n3\n
// @lcpr case=end

 */

