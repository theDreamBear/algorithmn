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
        while (pos < k and l1 + 1 < nums1.size()) {
            auto it = upper_bound(nums2.begin(), nums2.end(), nums1[l1 + 1]);
            for (auto beg = nums2.begin(); beg != it; beg++) {
                ans[pos++] = { nums1[l1], *beg };
            }
            ++l1;
        }
        for (int i = 0; i < nums2.size() and pos < k; i++) {
            ans[pos++] = { nums1.back(), nums2[i] };
        }
        return ans;
    }

    vector<vector<int>> kSmallestPairs_heap(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        auto cmp = [&](const pair<int, int>& bottom, const pair<int, int>& top) {
            return nums1[bottom.first] + nums2[bottom.second] > nums1[top.first] + nums2[top.second];
            };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> small(cmp);
        for (int i = 0; i < nums1.size(); i++) {
            small.push({ i, 0 });
        }
        while (ans.size() < k and !small.empty()) {
            auto [l, r] = small.top();
            small.pop();
            ans.push_back({ nums1[l], nums2[r] });
            if (r + 1 < nums2.size()) {
                small.push({ l ,r + 1 });
            }
        }
        return ans;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        auto counter = [&](int value) {
            int ct = 0;
            for (int i = 0; i < m; i++) {
                int low = 0, high = n - 1;
                while (low + 1 < high) {
                    int mid = (low + high) >> 1;
                    if (nums1[i] + nums2[mid] > value) {
                        high = mid;
                    }
                    else {
                        low = mid;
                    }
                }
                if (nums1[i] + nums2[high] <= value) {
                    ct += (high + 1);
                }
                else if (nums1[i] + nums2[low] <= value) {
                    ct += (low + 1);
                }
                else {
                    break;
                }
            }
            return ct;
        };
        int sum = 0;
        int low = nums1[0] + nums2[0], high = nums1[m - 1] + nums2[n - 1];
        while (low + 1 < high) {
            int mid = ((high - low) >> 1) + low;
            if (counter(mid) >= k) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        if (counter(low) >= k) {
            sum = low;
        }
        else {
            sum = high;
            int ch = counter(high);
            if (ch < k) {
                k = ch;
            }
        }
        vector<vector<int>> ans(k);
        int pos = 0;
        // < sum 的
        for (int i = 0; i < m; i++) {
            int j = 0;
            if (nums1[i] + nums2[j] > sum) {
                break;
            }
            while (j < n and nums1[i] + nums2[j] < sum) {
                ans[pos++] = {nums1[i], nums2[j++]};
            }
        }
        // == sum
        #ifdef VV
        for (int i = 0; i < m and pos < k; i++) {
            int j = 0;
            while (j < n and nums1[i] + nums2[j] < sum) {
                j++;
            }
            while (j < n and nums1[i] + nums2[j] == sum and pos < k) {
                ans[pos++] = {nums1[i], nums2[j++]};
            }
        }
        #else
        int j = n - 1;
        for (int i = 0; i < m and pos < k; i++) {
            int sb = i;
            while (i + 1 < m and nums1[i] == nums1[i + 1]) {
                i++;
            }
            while (j >= 0 and nums1[i] + nums2[j] > sum) {
                --j;
            }
            int se = j;
            while (j > 0 and nums2[j] == nums2[j - 1]) {
                j--;
            }
            if (j >= 0) {
                if (nums1[i] + nums2[j] != sum) {
                    continue;
                }
                int count = min(k - pos, (i - sb + 1) * (se - j + 1));
                for (int x = 0; x < count; x++) {
                    ans[pos++] = {nums1[i], nums2[j]};
                }
            }
        }
        #endif
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

