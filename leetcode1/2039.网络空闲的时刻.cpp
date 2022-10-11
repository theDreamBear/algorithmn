/*
 * @lc app=leetcode.cn id=2039 lang=cpp
 *
 * [2039] 网络空闲的时刻
 */

// @lc code=start
class Solution {
public:
    struct Vertex {
        vector<int> adjiacent;
    };

    // 求从0 出发的单源最短路径
    int networkBecomesIdle_1(vector<vector<int>>& edges, vector<int>& patience) {
        int n = (int)patience.size();
        vector<Vertex> G(n);
        for (auto& vec: edges) {
            int from = vec[0];
            int to = vec[1];
            G[from].adjiacent.push_back(to);
            G[to].adjiacent.push_back(from);
        }
        vector<int> distacne(n, INT_MAX);
        vector<bool> visited(n);
        distacne[0] = 0;

        for (int i = 0; i < n; i++) {
            int v = -1;
            for (int j = 0; j < n; j++) {
                if (visited[j]) {
                    continue;
                }
                if (v == -1 || distacne[v] > distacne[j]) {
                    v = j;
                }
            }
            visited[v] = true;
            if (v == -1) {
                break;
            }
            for (auto & adj : G[v].adjiacent) {
                if (distacne[adj] > distacne[v] + 1) {
                    distacne[adj] = distacne[v] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int rtt = distacne[i] * 2;
            int left = (rtt % patience[i] == 0) ? patience[i] : rtt % patience[i];
            ans = max(rtt * 2 - left + 1, ans);
        }
        return ans;
    }

    int networkBecomesIdle2(vector<vector<int>>& edges, vector<int>& patience) {
        int n = (int)patience.size();
        vector<Vertex> G(n);
        for (auto& vec: edges) {
            int from = vec[0];
            int to = vec[1];
            G[from].adjiacent.push_back(to);
            G[to].adjiacent.push_back(from);
        }
        vector<int> distacne(n, INT_MAX);
        vector<bool> visited(n);
        distacne[0] = 0;
        priority_queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.top();
            q.pop();
            for (auto adj : G[node].adjiacent) {
                if (distacne[adj] > distacne[node] + 1) {
                    distacne[adj] = distacne[node] + 1;
                    q.push(adj);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int rtt = distacne[i] * 2;
            int left = (rtt % patience[i] == 0) ? patience[i] : rtt % patience[i];
            ans = max(rtt * 2 - left + 1, ans);
        }
        return ans;
    }

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = (int)patience.size();
        vector<Vertex> G(n);
        for (auto& vec: edges) {
            int from = vec[0];
            int to = vec[1];
            G[from].adjiacent.push_back(to);
            G[to].adjiacent.push_back(from);
        }
        vector<int> distacne(n, INT_MAX);
        vector<bool> visited(n);
        distacne[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                for (auto adj: G[node].adjiacent) {
                    if (distacne[adj] == INT_MAX) {
                        distacne[adj] = distacne[node] + 1;
                        q.push(adj);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int rtt = distacne[i] * 2;
            int left = (rtt % patience[i] == 0) ? patience[i] : rtt % patience[i];
            ans = max(rtt * 2 - left + 1, ans);
        }
        return ans;
    }
};
// @lc code=end

