/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;
// @lc code=start
class Solution {
public:
    static constexpr int MAX_N = 101;
    static constexpr int MY_INT_MAX = 0x7fffffff;
    static constexpr int UNREACHABLE = -1;

    void myfill2(int (*ah)[MAX_N], int rows, int cols, int v) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ah[i][j] = v;
            }
        }
    }
    // // 最短路径数组最大值 
    int networkDelayTime_old(vector<vector<int>>& times, int N, int K) {
        int distance[MAX_N];
        int visit[MAX_N];
        int mp[MAX_N][MAX_N];
        // 预处理记录数组
        fill(distance, distance + MAX_N, MY_INT_MAX);
        fill(visit, visit + MAX_N, 0);
        myfill2(mp, MAX_N, MAX_N, -1);

        // 初始化矩阵
        for (int i = 0; i < times.size(); ++i) {
            int from = times[i][0];
            int to = times[i][1];
            int cost = times[i][2];
            mp[from][to] = cost;
        }
        
        distance[K] = 0;

        for (int i = 0; i < N; ++i) {
            int visitNode = -1;
            // 找到当前距离最小点
            for (int idx = 1; idx < N + 1; ++idx) {
                if (!visit[idx] && (visitNode == -1 || distance[idx] < distance[visitNode])) {
                    visitNode = idx;
                }
            }
            visit[visitNode] = 1;
            for (int u = 1; u < N + 1; ++u) {
                if (mp[visitNode][u] != -1 && distance[visitNode] != MY_INT_MAX) {
                    distance[u] = min(distance[u], mp[visitNode][u] + distance[visitNode]);
                }
            }
        }
        int r = -1;
        for (int i = 1; i < N + 1; ++i) {
            if (distance[i] == MY_INT_MAX) {
                return -1;
            }
            if (distance[i] > r) {
                r = distance[i];
            }
        }
        return r;
    }


    /*
    1. 定义:  Ds
    
    
    
    */
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // char* pt = NULL;
        // *pt = 1;
        int distance[MAX_N];
        int visit[MAX_N];
        // 预处理记录数组
        fill(distance, distance + MAX_N, MY_INT_MAX);
        fill(visit, visit + MAX_N, 0);
        distance[K] = 0;
        // 邻接表
        unordered_map<int, vector<pair<int, int>>> costs;
        for (int i = 0; i < times.size(); ++i) {
            int from = times[i][0];
            int to = times[i][1];
            int c = times[i][2];
            costs[from].push_back({to, c});
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > minHeap;
        minHeap.push({0, K});
        
        while(!minHeap.empty()) {
            auto node = minHeap.top();
            minHeap.pop();
            int d = node.first;
            int v = node.second;

            if (visit[v]) {
                continue;
            }
            visit[v] = 1;
            int mv = -1;
            for (int i = 0; i < costs[v].size(); ++i) {
                int t = costs[v][i].first;
                int cc = costs[v][i].second;
                if (!visit[t]) {
                    distance[t] = min(distance[t], d + cc);
                    minHeap.push({distance[t], t});
                }
            }
        }
        int ret = -1;
        for (int i = 1; i < N + 1; ++i) {
            if (distance[i] == MY_INT_MAX) {
                return -1;
            }
            if (ret < distance[i]) {
                ret = distance[i];
            }
        }
        return ret;
    }
};
// @lc code=end

