/*
 * @lc app=leetcode.cn id=1483 lang=cpp
 * @lcpr version=30204
 *
 * [1483] 树节点的第 K 个祖先
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class TreeAncestor {
public:
    vector<vector<int>> fa;

    TreeAncestor(int n, vector<int>& parent):fa(log2(n) + 1, vector<int>(n, -1)) {
        for (int i = 0; i < n; i++) {
            fa[0][i] = parent[i];
        }
        for (int k = 1; k < fa.size(); k++) {
            for (int i = 0; i < n; i++) {
                if (fa[k - 1][i] != -1) {
                    fa[k][i] = fa[k - 1][fa[k - 1][i]];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int m = log2(k); m >= 0; m--) {
            if ((1 << m) <= k) {
                if (fa[m][node] == -1) return -1;
                node = fa[m][node];
                k -= 1 << m;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end



/*
// @lcpr case=start
// ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"][[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]\n
// @lcpr case=end

 */

