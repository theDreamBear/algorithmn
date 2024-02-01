/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30114
 *
 * [238] 除自身以外数组的乘积
 */


// @lcpr-template-start
#include <numeric>
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
    /*
        暴力解法
        时间复杂度 10^5 * 10^5
    */
    vector<int> productExceptSelf_violatile(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int m = 1;
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                m *= nums[j];
            }
            ans[i] = m;
        }
        return ans;
    }

    vector<int> productExceptSelf1(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1);
        for (int i = 1, j = n - 2; i < n and j >= 0; i++, j--) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[j] = suffix[j + 1] * nums[j + 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }

    /*
        这个还不错
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int r = 1;
        for (int j = n - 1; j >= 0; j--) {
            ans[j] = ans[j] * r;
            r *= nums[j];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

