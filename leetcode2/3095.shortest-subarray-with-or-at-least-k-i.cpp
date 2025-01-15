/*
 * @lc app=leetcode.cn id=3095 lang=cpp
 * @lcpr version=30204
 *
 * [3095] 或值至少 K 的最短子数组 I
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
    int minimumSubarrayLength1(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int val = 0;
                for (int k = j; k <= i; k++) {
                    val |= nums[k];
                } 
                if (val >= k and i - j + 1 < ans) {
                    ans = i - j + 1;
                }
            }
        }
        return ans == n + 1 ? -1 : ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= k) return 1;
            int j = i - 1;
            while (j >= 0 and (nums[i] | nums[j]) != nums[j]) {
                nums[j] |= nums[i];
                if (nums[j] >= k and i - j + 1 < ans) {
                    ans = i - j + 1;
                }
                j--;
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,1,8]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */

