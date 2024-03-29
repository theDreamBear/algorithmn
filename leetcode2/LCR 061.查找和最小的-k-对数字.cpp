/*
 * @lc app=leetcode.cn id=LCR 061 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 061] 查找和最小的 K 对数字
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
    vector<vector<int>> kSmallestPairs_bad_logic(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans(k);
        int pos = 0, l1 = 0;
        while (pos  < k and l1 + 1 < nums1.size()) {
            auto it = upper_bound(nums2.begin(), nums2.end(), nums1[l1 + 1]);
            for (auto beg = nums2.begin(); beg != it; beg++) {
                ans[pos++] = {nums1[l1], *beg};
            }
            ++l1;
        }
        for (int i = 0; i < nums2.size() and pos < k; i++) {
            ans[pos++] = {nums1.back(), nums2[i]};
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3]\n3\n
// @lcpr case=end

 */

