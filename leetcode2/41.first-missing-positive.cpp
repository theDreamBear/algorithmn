/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30204
 *
 * [41] 缺失的第一个正数
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
    int firstMissingPositive1(vector<int>& nums) {
        ranges::sort(nums);
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int exp = 1;
        auto it = upper_bound(nums.begin(), nums.end(), 0);
        if (it == nums.end()) {
            return 1;
        }
        int i = it - nums.begin();
        for (; i < nums.size(); i++) {
            if (nums[i] != exp) return exp;
            exp++;
        }
        return exp;
    }

    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            // 每次交换都能生成一个符合条件的位置
            // nums[i] - 1位置还不符合要求才交换
            // 所以最多交换 n次, 故时间复杂度是 n
            while (nums[i] > 0 and nums[i] <= nums.size() and nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 != nums[i]) return i + 1;
        }
        return nums.size() + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */

