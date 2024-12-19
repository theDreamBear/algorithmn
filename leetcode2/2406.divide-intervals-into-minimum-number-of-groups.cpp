/*
 * @lc app=leetcode.cn id=2406 lang=cpp
 * @lcpr version=30204
 *
 * [2406] 将区间分为最少组数
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
    class UF {
    public:
        int n;
        vector<int> fa;

        UF(int n): fa(n) {
            this->n = n - 1;
            iota(fa.begin(), fa.end(), 0);
        }

        int find(int u) {
            if (fa[u] == u) {
                return u;
            }
            return fa[u] = find(fa[u]);
        }

        void merge(int u) {
            int pv = find(u + 1);
            fa[u] = pv;
        }
    };

    int minGroups(vector<vector<int>>& is) {
        // 按照left从小到大排序
        ranges::sort(is, {}, [&](auto& a) {
            return a[0];
        });
        int n = is.size();
        vector<int> fa(n);
        iota(fa.begin(), fa.end(), 0);
        int ans = n;

        auto find = [&](auto&& find, int u) {
            if (fa[u] == u) return u;
            return fa[u] = find(find, fa[u]);
        };

        auto merge = [&](int u, int v) {
            int pu = find(find, u);
            int pv = find(find, v);
            if (pu == pv) return;
            ans--;
            if (pu < pv) {
                fa[pv] = pu;
            } else {
                fa[pu] = pv;
            }
        };
        UF uf(n + 1);
        for (int i = 0; i < n; i++) {
            int left = is[i][0], right = is[i][1];
            auto it = ranges::upper_bound(is, right, {}, [](auto& a) {
                return a[0];
            }) - is.begin();
            if (it != n) {
                // 暴力找到下一个可以拼接的
                // while (it < n and fa[it] != it) {
                //     it++;
                // }
                // if (it != n) {
                //     merge(i, it);
                // }

                // 并查集加速
                auto x = uf.find(it);
                if (x != n) {
                    merge(i, x);
                    uf.merge(x);
                }
            }
        };
        return ans;
    }
    // 查分
    int minGroups1(vector<vector<int>> &intervals) {
        map<int, int> diff;
        for (auto &p : intervals)
            ++diff[p[0]], --diff[p[1] + 1];
        int ans = 0, sum = 0;
        for (auto &[_, d] : diff)
            ans = max(ans, sum += d);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[5,10],[6,8],[1,5],[2,3],[1,10]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[5,6],[8,10],[11,13]]\n
// @lcpr case=end

 */

 
