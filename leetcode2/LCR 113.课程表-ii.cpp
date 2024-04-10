/*
 * @lc app=leetcode.cn id=LCR 113 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 113] 课程表 II
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> ans;
        for (auto & vec : prerequisites) {
            int pre = vec[1];
            int cur = vec[0];
            adj[pre].push_back(cur);
            indegree[cur]++;

        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            ans.push_back(v);
            for (auto next : adj[v]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */

