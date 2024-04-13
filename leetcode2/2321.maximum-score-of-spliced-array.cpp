/*
 * @lc app=leetcode.cn id=2321 lang=cpp
 * @lcpr version=30122
 *
 * [2321] 拼接数组的最大分数
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            nums1[i] -= nums2[i];
        }
        int ma = nums1[0], mas = nums1[0];
        int mn = nums1[0], mns = nums1[0];
        for (int i = 1; i < n; i++) {
            mas = max(mas + nums1[i], nums1[i]);
            ma = max(ma, mas);

            mns = min(mns + nums1[i], nums1[i]);
            mn = min(mn, mns);
        }
        return max({s1, s2, s1 - mn, s2 + ma});
    }
};
// @lc code=end



/*
// @lcpr case=start
// [60,60,60]\n[10,90,10]\n
// @lcpr case=end

// @lcpr case=start
// [20,40,20,70,30]\n[50,20,50,40,20]\n
// @lcpr case=end

// @lcpr case=start
// [7,11,13]\n[1,1,1]\n
// @lcpr case=end

 */

