// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2860 lang=cpp
 * @lcpr version=30204
 *
 * [2860] 让所有学生保持开心的分组方法数
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
    // 需要看懂题目
    int countWays1(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int ans = 0;
        // pt > nums[i]
        // pt < nums[i]
        // 枚举选择人数
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                if (i < nums[0]) {
                    ans++;
                }
            } else if (i == n) {
                if (n > nums[n - 1]) {
                    ans++;
                }
            } else {
                if (i > nums[i - 1] and i < nums[i]) {
                    ans++;
                }
            }
        }
        return ans;
    }

    int countWays(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int ans = (nums[0] > 0) + 1;
        // pt > nums[i]
        // pt < nums[i]
        // 枚举选择人数
        for (int i = 1; i < n; i++) {
            if (i > nums[i - 1] and i < nums[i]) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countWays
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,1]\n
// @lcpr case=end

// @lcpr case=start
// [6,0,3,3,6,7,2,7]\n
// @lcpr case=end

 */

