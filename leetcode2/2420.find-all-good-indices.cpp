/*
 * @lc app=leetcode.cn id=2420 lang=cpp
 * @lcpr version=30204
 *
 * [2420] 找到所有好下标
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
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n), suf(n);
        pre[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) pre[i] = pre[i - 1] + 1;
            else {
                pre[i] = 1;
            }
        }
        suf[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) suf[i] = suf[i + 1] + 1;
            else {
                suf[i] = 1;
            }
        } 
        vector<int> ans;
        for (int i = k; i < n - k; i++) {
            if (pre[i - 1] >= k and suf[i + 1] >= k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,1,1,3,4,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,2]\n2\n
// @lcpr case=end

 */

