// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30122
 *
 * [4] 寻找两个正序数组的中位数
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
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays1(nums2, nums1);
        }
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        while (left <= right) {
            int i = (right - left) / 2 + left;
            int j = (m + n + 1) / 2 - i;
            if (j != 0 and i != m and nums2[j - 1] > nums1[i]) {
                left = i + 1;
            }
            else if (i != 0 and j != n and nums1[i - 1] > nums2[j]) {
                right = i - 1;
            }
            else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0) {
                    maxLeft = nums1[i - 1];
                }
                else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) & 0x1) {
                    return maxLeft;
                }
                int maxRight = 0;
                if (i == m) {
                    maxRight = nums2[j];
                }
                else if (j == n) {
                    maxRight = nums1[i];
                }
                else {
                    maxRight = min(nums1[i], nums2[j]);
                }
                return (maxLeft + maxRight) / 2.0;
            }
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        function<double(int, int, int, int, int)> kth = [&](int l1, int h1, int l2, int h2, int k)->double {
            int ans = 0;
            while (true) {
                if (l1 > h1) {
                    ans = nums2[l2 + k - 1];
                    break;
                }
                if (l2 > h2) {
                    ans = nums1[l1 + k - 1];
                    break;
                }
                if (k == 1) {
                    ans = min(nums1[l1], nums2[l2]);
                    break;
                }
                int mid = k >> 1;
                int lv = l1 + mid - 1 <= h1 ? nums1[l1 + mid - 1] : nums1[h1];
                int rv = l2 + mid - 1 <= h2 ? nums2[l2 + mid - 1] : nums2[h2];
                if (lv <= rv) {
                    k -= min(mid, h1 - l1 + 1);
                    l1 += mid;
                } else {
                    k -= min(mid, h2 - l2 + 1);
                    l2 += mid;
                }
            }
            return ans;
        };
        if ((m + n) & 0x1) {
            return kth(0, m - 1, 0, n - 1, (m + n + 1) / 2);
        }
        return (kth(0, m - 1, 0, n - 1, (m + n + 1) / 2) +
                kth(0, m - 1, 0, n - 1, (m + n + 2) / 2)) / 2.0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

