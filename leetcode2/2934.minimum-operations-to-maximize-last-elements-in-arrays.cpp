/*
 * @lc app=leetcode.cn id=2934 lang=cpp
 * @lcpr version=30204
 *
 * [2934] 最大化数组末位元素的最少操作次数
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
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        auto cal = [&]() {
            int r1 = 0;
            for (int i = 0; i + 1 < n; i++) {
                if (nums1[i] <= nums1[n - 1] and nums2[i] <= nums2[n - 1]) {
                    continue;
                }
                if (nums1[i] <= nums2[n - 1] and nums2[i] <= nums1[n - 1]) {
                    r1++;
                    continue;
                }
                r1 = n + 1;
                break;
            }
            return r1;
        };
        auto r1 = cal();
        swap(nums1[n - 1], nums2[n - 1]);
        auto r2 = cal();
        int x = min(r1, r2 + 1);
        return x > n ? -1 : x;
    } 
};
// @lc code=end



/*
// @lcpr case=start
// [1,2\n[4,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,5\n[8,8,4,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,5\n[2,5,3]\n
// @lcpr case=end

 */

