/*
 * @lc app=leetcode.cn id=2871 lang=cpp
 * @lcpr version=30204
 *
 * [2871] 将数组分割成最多数目的子数组
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSubarrays1(vector<int>& nums) {
        //
        int n = nums.size();
        int k = log2(n);
        vector<vector<int>> st(k + 1, vector<int>(n));
        for (int i = 0; i < n; i++) {
            st[0][i] = nums[i];
        }
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                st[i][j] = st[i - 1][j];
                if (j + (1 << (i - 1)) < n) {
                    st[i][j] &= st[i - 1][j + (1 << (i - 1))];
                }
            }
        }
        auto query = [&](int l, int r) {
            int d = log2(r - l + 1);
            return st[d][l] & st[d][r - (1 << d) + 1];
        };
        int mm = query(0, n - 1);
        auto binary_seach = [&](int pos) {
            int low = pos, high = n - 1;
            while (low + 1 < high) {
                int mid = low + (high - low) / 2;
                if (query(pos, mid) > mm) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            if (query(pos, low) == mm) {
                return low;
            }
            if (query(pos, high) == mm) {
                return high;
            }
            return -1;
        };
        int ans = mm == 0 ? 0 : 1;
        for (int i = 0; i < n and mm == 0;) {
            i = binary_seach(i);
            if (i != -1) {
                ans++;
                i++;
            } else {
                break;
            }
        }
        return ans;
    }

    int maxSubarrays(vector<int>& nums) {
        //
        int n = nums.size();
        int ans = 0;
        int cur = nums[0];
        for (int i = 0; i < n; i++) {
            cur &= nums[i];
            if (cur == 0) {
                ans++;
                if (i + 1 < n) cur = nums[i + 1];
            }
        }
        return ans == 0 ? 1 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,7,1,3]\n
// @lcpr case=end

 */

