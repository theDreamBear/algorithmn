/*
 * @lc app=leetcode.cn id=LCR 116 lang=cpp
 * @lcpr version=30114
 *
 * [LCR 116] 省份数量
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
    class UF {
    public:
        vector<int> parent;
        int ct = 0;

        UF(int n) :parent(n){
            iota(parent.begin(), parent.end(), 0);
            ct = n;
        }

        int find(int v) {
            if (parent[v] == parent[parent[v]]) {
                return parent[v];
            }
            return parent[v] = find(parent[v]);
        }

        void merge(int v, int w) {
            int pv = find(v);
            int pw = find(w);
            if (pv == pw) {
                return;
            }
            --ct;
            parent[pv] = pw;
        }

        int count() const {
            return ct;
        }
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UF uf(n);
        for (int v = 0; v < n; v++) {
            for (int w = 0; w < n; w++) {
                if (isConnected[v][w]) {
                    uf.merge(v, w);
                }
            }
        }
        return uf.count();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */

