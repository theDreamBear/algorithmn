/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 * @lcpr version=30204
 *
 * [2055] 蜡烛之间的盘子
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
    // 2  5  9
    // 3 6
    // 二分
    vector<int> platesBetweenCandles1(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') idx.push_back(i);
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int left = queries[i][0], right = queries[i][1];
            // 找第一个>= left 最后一个<= right 的蜡烛
            auto pf = ranges::lower_bound(idx, left);
            auto pe = ranges::upper_bound(idx, right);
            // if (pf != idx.end() and pe != idx.begin()) {
            //     --pe;
            //     int l = pf - idx.begin(), r = pe - idx.begin();
            //     if (l < r) {
            //         ans[i] = idx[r] - idx[l] - (r - l);
            //     }
            // }
            if (pf != idx.end() and pe != idx.begin() and pf < pe) {
                --pe;
                ans[i] = *pe - *pf - (pe - pf);
            }
        }
        return ans;
    }

    // left, right
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> left(n), right(n), sum(n + 1);
        for (int i = 0, p = -1; i < n; i++) {
            sum[i + 1] = sum[i];
            if (s[i] == '|') {
                p = i;
            } else {
                sum[i + 1]++;
            }
            left[i] = p;
        }
        for (int i = n-1, q = n; i >= 0; i--) {
            if (s[i] == '|') {
                q = i;
            }
            right[i] = q;
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            if (left[r] > right[l]) {
                ans[i] = sum[left[r] + 1] - sum[right[l]];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "**|**|***|"\n[[2,5],[5,9]]\n
// @lcpr case=end

// @lcpr case=start
// "***|**|*****|**||**|*"\n[[1,17],[4,5],[14,17],[5,11],[15,16]]\n
// @lcpr case=end

 */

