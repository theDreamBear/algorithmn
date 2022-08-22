/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees_violate(int n, vector<vector<int>> &edges) {
        vector<int> ans;
        vector<vector<int>> Graph(n);
        for (auto &vec: edges) {
            int one = vec[0];
            int two = vec[1];
            Graph[one].push_back(two);
            Graph[two].push_back(one);
        }
        int min_depth = n;
        function<int(int)> get_depth = [&](int root) -> int {
            vector<int> visited(n);
            int dep = 0;
            queue<int> q;
            q.push(root);
            visited[root] = 1;
            while (!q.empty()) {
                ++dep;
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    auto node = q.front();
                    q.pop();
                    for (auto child: Graph[node]) {
                        if (visited[child]) {
                            continue;
                        }
                        visited[child] = 1;
                        q.push(child);
                    }
                }
            }
            return dep;
        };
        for (int i = 0; i < n; i++) {
            int dep = get_depth(i);
            if (dep < min_depth) {
                ans.clear();
                ans.push_back(i);
                min_depth = dep;
            } else if (dep == min_depth) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    struct Node {
        bool know = false;
        int distance = 0;
        int pre = -1;
        vector<int> adjacent;
    };

    void init(vector<Node>& nodes) {
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].pre = -1;
            nodes[i].know = false;
            nodes[i].distance = 0;
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<int> ans;
        vector<Node> nodes(n);
        for (auto &vec: edges) {
            int one = vec[0];
            int two = vec[1];
            nodes[one].adjacent.push_back(two);
            nodes[two].adjacent.push_back(one);
        }
        // 求起点的问题
        int root = -1;
        int max_depth = INT_MIN;
        function<void(int, int , int)> dfs = [&](int i, int pre, int d) {
            if (root == -1 || max_depth < d) {
                root = i;
                max_depth = d;
            }
            nodes[i].know = true;
            nodes[i].pre = pre;
            nodes[i].distance = d;
            for (int nodeId: nodes[i].adjacent) {
                if (nodes[nodeId].know) {
                    continue;
                }
                dfs(nodeId, i, d + 1);
            }
        };
        dfs(0, -1, 0);
        init(nodes);
        dfs(root, -1, 0);
        unordered_set<int> added;
        for (int i = 0; i < n; i++) {
            if (nodes[i].distance == max_depth) {
                int half = (max_depth + 1) / 2;
                int j = i;
                while (-1 != j) {
                    if (nodes[j].distance == half) {
                        if (added.count(j) == 0) {
                            ans.push_back(j);
                        }
                        added.insert(j);
                        if (max_depth % 2 != 0) {
                            j = nodes[j].pre;
                            if (added.count(j) == 0) {
                                ans.push_back(j);
                            }
                            added.insert(j);
                            break;
                        }
                    }
                    j = nodes[j].pre;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

