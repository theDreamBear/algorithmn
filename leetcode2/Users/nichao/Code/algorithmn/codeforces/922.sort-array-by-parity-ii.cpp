/*
 * @lc app=leetcode.cn id=922 lang=cpp
 * @lcpr version=30204
 *
 * [922] 按奇偶排序数组 II
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
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // i标记偶数下标
        // j标记当
        for (int i = 0, j = 1; i < nums.size() and j < nums.size();) {
            if (nums[i] % 2 != 0) {
                if (nums[j] % 2 == 0) {
                    swap(nums[i], nums[j]);
                    i += 2;
                }
                j += 2;
                continue;
            } else {
                i += 2;
            }
        }
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

 */

