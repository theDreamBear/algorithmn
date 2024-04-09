/*
 * @lc app=leetcode.cn id=LCR 118 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 118] 冗余连接
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
#include <numeric>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    class UF {
     public:
        vector<int> parent;
        vector<int> rank;

        UF(int n) : parent(n), rank(n) {
            iota(parent.begin(), parent.end(), 0);
            fill(rank.begin(), rank.end(), 1);
        }

        int find(int v) {
            if (v == parent[v]) {
                return v;
            }
            return parent[v] = find(parent[v]);
        }

        bool isConnected(int v, int w) {
            return find(v) == find(w);
        }

        void merge(int v, int w) {
            int pv = find(v);
            int pw = find(w);
            if (rank[pv] >= rank[pw]) {
                rank[pv] += rank[pw];
                parent[pw] = pv;
            } else {
                rank[pw] += rank[pv];
                parent[pv] = pw;
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        UF uf(edges.size() + 1);
        for (const auto& vec : edges) {
            int v = vec[0], w = vec[1];
            if (uf.isConnected(v, w)) {
                ans = vec;
            } else {
                uf.merge(v, w);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,4],[1,5]]\n
// @lcpr case=end

 */

