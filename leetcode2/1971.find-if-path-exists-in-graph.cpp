/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 * @lcpr version=30114
 *
 * [1971] 寻找图中是否存在路径
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
    class Graph {
    public:
        vector<vector<int>> data;
        int v;

        Graph(int v) : data(v), v(v) {}

        void addEdge(int v, int w) {
            data[v].push_back(w);
            data[w].push_back(v);
        }

        void addEdge(vector<vector<int>>& edges) {
            for (auto& vec : edges) {
                addEdge(vec[0], vec[1]);
            }
        }

        int V() const {
            return v;
        }

        const vector<int>& adj(int v) const{
            return data[v];
        }
    };

    class DfsSearch {
    public:
        Graph& g;
        vector<int> marked;
        int e;
        bool dfs(int s, int e) {
            marked[s] = 1;
            if (s == e) {
                return true;
            }
            for (const auto w : g.adj(s)) {
                if (marked[w]) {
                    continue;
                }
                if (dfs(w, e)) {
                    return true;
                }
            }
            return false;
        }

        DfsSearch(Graph& g, int v, int w):g(g), marked(g.V()) {
            e = w;
            dfs(v, w);
        }

        bool can() const {
            return marked[e];
        }
    };


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        Graph g(n);
        g.addEdge(edges);
        return DfsSearch(g, source, destination).can();
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1],[1,2],[2,0]]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[3,5],[5,4],[4,3]]\n0\n5\n
// @lcpr case=end

 */

