/*
 * @lc app=leetcode.cn id=LCR 110 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 110] 所有可能的路径
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
    class PathSearch {
     private:
        const vector<vector<int>>& graph;
        int n;
        int target;

        vector<vector<int>> ans;
        vector<int> path;


        void backtrack(int v) {
            if (v == target) {
                ans.push_back(path);
                return;
            }
            for (auto w : graph[v]) {
                path.push_back(w);
                backtrack(w);
                path.pop_back();
            }
        }

     public:
        PathSearch(const vector<vector<int>>& graph, int target): graph(graph), n(graph.size()), target(target) {
            path.push_back(0);
            backtrack(0);
        }

        vector<vector<int>>& result() {
            return ans;
        }
    };

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        PathSearch ps(graph, graph.size() - 1);
        return ps.result();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[2],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[2],[3],[]]\n
// @lcpr case=end

 */

