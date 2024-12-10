/*
 * @lc app=leetcode.cn id=2717 lang=cpp
 * @lcpr version=30204
 *
 * [2717] 半有序排列
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
    int semiOrderedPermutation(vector<int>& nums) {
        int ans = 0;
        int p = 0;
        while (nums[p] != 1) p++;
        while (p) {
            swap(nums[p], nums[p - 1]);
            p--;
            ans++;
        }
        int n = nums.size();
        p = 0;
        while (nums[p] != n) p++;
        while (p + 1 < n) {
            swap(nums[p], nums[p + 1]);
            p++;
            ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,4,2,5]\n
// @lcpr case=end

 */

