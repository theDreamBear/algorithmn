/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        struct Node {
            bool know{};
            unordered_set<Node *> adjacent;
        };
        int n = edges.size();
        Node G[n];
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0] - 1;
            int to = edges[i][1] - 1;

            G[from].adjacent.insert(&G[to]);

            G[to].adjacent.insert(&G[from]);
        }
        auto bfs = [&](int id) -> bool {
            int from = edges[id][0] - 1;
            int to = edges[id][1] - 1;
            G[from].adjacent.erase(&G[to]);
            G[to].adjacent.erase(&G[from]);

            queue<Node *> q;
            q.push(&G[from]);
            G[from].know = true;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    auto node = q.front();
                    q.pop();
                    for (auto &nei: node->adjacent) {
                        if (nei->know) {
                            continue;
                        }
                        nei->know = true;
                        q.push(nei);
                    }
                }
            }
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (!G[i].know) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                for (int i = 0; i < n; i++) {
                   G[i].know = false;
                }
            }
            G[from].adjacent.insert(&G[to]);
            G[to].adjacent.insert(&G[from]);
            return flag;
        };
        int i = edges.size() - 1;
        for (; i >= 0; i--) {
            if (bfs(i)) {
                break;
            }
        }
        return edges[i];
    }
};
// @lc code=end

