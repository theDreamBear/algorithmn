/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
// 找环
class Solution {
public:
    struct Vertex {
        int know{};
        vector<int> adjacent;
    };

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Vertex> nodes(numCourses);
        vector<int> onStack(numCourses);
        for (auto& vec : prerequisites) {
            int to = vec[0];
            int from = vec[1];
            nodes[from].adjacent.push_back(to);
        }
        function<bool(int v)> dfs = [&](int v) {
            nodes[v].know = true;
            onStack[v] = 1;
            for (auto adj : nodes[v].adjacent) {
                if (!nodes[adj].know) {
                    if (!dfs(adj)) {
                        return false;
                    }
                } else if (onStack[adj]) {
                    return false;
                }
            }
            onStack[v] = 0;
            return true;
        };
        for (int i = 0; i < nodes.size(); i++) {
            if (!nodes[i].know) {
                if (!dfs(i)) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

