/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
public:
    struct Node {
        vector<Node*> adjacents;
        vector<int> costs;
        bool know = false;
        int distance = INT_MAX;
        Node* pre = nullptr;
    };

    void print(Node* node) {
        if (node->pre) {
            print(node->pre);
        }
        cout << node->distance << "\t";
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Node nodes[n];
        for (auto& vec : times) {
            int from = vec[0] - 1;
            int to = vec[1] - 1;
            int cost = vec[2];
            nodes[from].adjacents.push_back(&nodes[to]);
            nodes[from].costs.push_back(cost);
        }
        nodes[k - 1].distance = 0;
        for (;;) {
            // 找最短边
            int v = -1;
            for (int i = 0; i < n; i++) {
                if (nodes[i].know || nodes[i].distance == INT_MAX) {
                    continue;
                }
                if (v == -1 || nodes[i].distance < nodes[v].distance) {
                    v = i;
                }
            }
            if (v == -1) {
                break;
            }
            nodes[v].know = true;
            for (int nid = 0; nid < nodes[v].adjacents.size(); nid++) {
                auto neighbor = nodes[v].adjacents[nid];
                int cost = nodes[v].costs[nid];
                if (neighbor->know) {
                    continue;
                }
                if (neighbor->distance > nodes[v].distance + cost) {
                    neighbor->distance = nodes[v].distance + cost;
                    neighbor->pre = &nodes[v];
                }
            }
        }
        int max_cost = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nodes[i].distance == INT_MAX) {
                return -1;
            }
            max_cost = max(max_cost, nodes[i].distance);
            // print(&nodes[i]);
            // cout << endl;
        }
        return max_cost;
    }
};
// @lc code=end

