/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees_violate(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>> Graph(n);
        for (auto& vec : edges) {
            int one = vec[0];
            int two = vec[1];
            Graph[one].push_back(two);
            Graph[two].push_back(one);
        }
        int min_depth = n;
        function<int(int)> get_depth = [&](int root)->int {
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
                    for (auto child : Graph[node]) {
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

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>> Graph(n);
        for (auto& vec : edges) {
            int one = vec[0];
            int two = vec[1];
            Graph[one].push_back(two);
            Graph[two].push_back(one);
        }
        int root = 0;
        int cd = n;
        for (int i = 0; i < Graph.size(); i++) {
            if (Graph[i].size() < cd) {
                cd = Graph[i].size();
                root = i;
            }
        }
        struct Item {
            int node;
            vector<int> path;
        };
        vector<int> temp;
        function<void(int)> get_max = [&](int root)->void {
            vector<int> visited(n);

            Item* item = new Item;
            item->node = root;
            item->path.push_back(root);
            if (item->path.size() > temp.size()) {
                temp = item->path;
            }
            queue<Item*> q;
            q.push(item);
            visited[root] = 1;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    auto node = q.front();
                    q.pop();
                    for (auto child : Graph[node->node]) {
                        if (visited[child]) {
                            continue;
                        }
                        visited[child] = 1;
                        Item* item = new Item;
                        item->node = child;
                        item->path = node->path;
                        item->path.push_back(child);
                        if (item->path.size() > temp.size()) {
                            temp = item->path;
                        }
                        q.push(item);
                    }
                }
            }
            return;
        };
        // 找到最长的那个链路
        get_max(root);

        int min_depth = n;
        function<int(int)> get_depth = [&](int root)->int {
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
                    for (auto child : Graph[node]) {
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

        for (int i = 0; i < temp.size(); i++) {
            int dep = get_depth(temp[i]);
            if (dep < min_depth) {
                ans.clear();
                ans.push_back(temp[i]);
                min_depth = dep;
            } else if (dep == min_depth) {
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

