/*
 * @lc app=leetcode.cn id=310 lang=cpp
 * @lcpr version=30114
 *
 * [310] 最小高度树
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
class Graph {
public:
    vector<vector<int>> data;
    int vnt;

    Graph(int n): data(n), vnt(n){}

    void addEdge(vector<vector<int>>& edges) {
        for (const auto& vec : edges) {
            data[vec[0]].push_back(vec[1]);
            data[vec[1]].push_back(vec[0]);
        }
    }

    const vector<int>& adj(int v) const{
        return data[v];
    }

    int V() const {
        return vnt;
    }
};

class Dfs{
public:
    const Graph& g;
    vector<int> ans;
    int min_depth = INT_MAX;

    Dfs(const Graph& g):g(g){}

    int depth(vector<int>& marked, int v) {
        int d = 1;
        marked[v] = 1;
        for (const auto w : g.adj(v)) {
            if (!marked[w]) {
                d = max(d, 1 + depth(marked, w));
            }
        }
        return d;
    }

    void search() {
        for (int v = 0; v < g.V(); v++) {
            vector<int> marked(g.V());

        }
    }
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[1,0],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]\n
// @lcpr case=end

 */

