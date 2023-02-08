/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution1 {
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

class Solution {
public:
    struct UnionFinder {
        int n;
        vector<int> fa;
        int count;

        UnionFinder(int n) : n(n), fa(n), count(n) {
            for (int i = 0; i < n; i++) {
                fa[i] = i;
            }
        }

        int find(int v) {
            if (fa[fa[v]] == fa[v]) {
                return fa[v];
            }
            fa[v] = find(fa[v]);
            return fa[v];
        }

        bool merge(int v, int w) {
            int l = find(v);
            int r = find(w);
            if (l == r) {
                return false;
            }
            fa[l] = r;
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        UnionFinder uf(edges.size());
        int pre = 0;
        int i = 0;
        for (; i < edges.size(); i++) {
            int v = edges[i][0] - 1;
            int w = edges[i][1] - 1;
            if (!uf.merge(v, w)) {
                return edges[i];
            }
        }
        return {};
    }
};
// @lc code=end

