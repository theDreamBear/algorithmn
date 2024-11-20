/*
 * @lc app=leetcode.cn id=3261 lang=cpp
 * @lcpr version=30204
 *
 * [3261] 统计满足 K 约束的子字符串数量 II
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
    #define get(ch) ch - 'a'
    // [a, b] -> [a, c] [c + 1, b]
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& q) {
        int m = q.size();
        vector<long long> ans(m);
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        // q按照left 排序
        // 并查集加速
        // vector<int> fa(m + 1);
        // for (int i = 0; i < m; i++) {
        //     fa[i] = i + 1;
        // }
        // auto find = [&](auto&& find, int u) {
        //     if (fa[u] == u) {
        //         return u;
        //     }
        //     return fa[u] = find(find, fa[u]);
        // };
        // auto merge = [&](auto&& merge, int u, int v) {
        //     int pu = find(find, u);
        //     int pv = find(find, v);
        //     if (pu == pv) {
        //         return;
        //     }
        //     if (pu < pv) {
        //         fa[pu] = pv;
        //     } else {
        //         fa[pv] = pu;
        //     }
        // };
        ranges::sort(idx, [&](int l, int r) {
            return q[l][0] < q[l][1];
        });
        int cnt[2]{};
        for (int left = 0, right = 0; right < s.size(); right++) {
            cnt[get(s[right])]++;
            while (cnt[0] > k and cnt[1] > k) {
                cnt[get(s[left++])]--;
            }
            // 右在区间

            // 左在区间

            // 都在区间
        }
    }
};
// @lc code=end



/*
// @lcpr case=start


// "0001111"\n2\n[[0,6]]\n
// @lcpr case=end

// @lcpr case=start
// "010101"\n1\n[[0,5],[1,4],[2,3]]\n
// @lcpr case=end

 */

