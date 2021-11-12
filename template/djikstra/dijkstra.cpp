#include<iostream>

#include<vector>
#include <climits>
#include<queue>
#include<algorithm>

using namespace std;

static constexpr int INTMAX = 0x7ffffff;
static constexpr int UNREACHABLE = -1;

// 起点已知最短路径
int dijkstra(const vector<vector<int>> &graph, int start, int target) {
    // 边界
    if (start == target) {
        return 0;
    }
    auto checkIndexFunc = [&](int index) {
        return index >= 0 && index < graph.size();
    };
    if (!checkIndexFunc(start) || !checkIndexFunc(target)) {
        return INT_MAX;
    }

    vector<int> distance(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false);
    distance[start] = 0;
    for (;;) {
        int minNode = -1;
        // 找一个当前距离最短点
        for (int nodeId = 0; nodeId < graph.size(); nodeId++) {
            if (!visited[nodeId] && (minNode == -1 || distance[nodeId] < distance[minNode])) {
                minNode = nodeId;
            }
        }
        // 没有找到能加入到当前图的点
        if (minNode == -1) {
            break;
        }
        visited[minNode] = true;
        for (int nextNode = 0; nextNode < graph[minNode].size(); ++nextNode) {
            // 连通
            if (graph[minNode][nextNode] == INT_MAX) {
                continue;
            }
            // 更新
            distance[nextNode] = min(distance[nextNode], distance[minNode] + graph[minNode][nextNode]);
        }
    }
    return distance[target];
}


int dijkstra_c(vector<vector<int>> costs, int start, int end) {
    vector<int> distance(costs.size(), INT_MAX);
     vector<bool> vistied(costs.size(), false);
    distance[start] = 0;
    for (int k = 0; k < costs.size(); ++k) {
        int v = -1;
        // 找到最
        for (int j = 0; j < distance.size(); ++j) {
            // 未访问点找最小的
            if (!vistied[j]) {
                if (v == -1 || distance[v] > distance[j]) {
                    j = v;
                }
            }
        }
        if (v == -1) {
            break;
        }
        vistied[v] = true;
        for (int i = 0; i < costs[v].size(); ++i) {
            // v, i 有路径
            if (costs[v][i] != INT_MAX) {
                if (distance[i] > distance[v] + costs[v][i]) {
                    distance[i] = distance[v] + costs[v][i];
                }
            }
        }
    }
    return distance[end];
}


// 使用优先级队列优化
int dijkstra(vector<vector<int>> costs, int start, int end) {
    int vCount = costs.size();
    vector<int> distance(vCount, INT_MAX);
    vector<bool> visited(vCount, false);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;
    minHeap.push({0, start});
    while (!minHeap.empty()) {
        // 最小点
        auto [c, v] = minHeap.top();
        minHeap.pop();
        // 不能更新
        if (distance[v] < c) {
            continue;
        }
        for (int i = 0; i < costs[v].size(); ++i) {
            if (costs[v][i] != INT_MAX && distance[i] > distance[v] + costs[v][i]) {
                distance[i] = distance[v] + costs[v][i];
                minHeap.push({distance[i], i});
            }
        }
    }
    return distance[end];
}


void floyd_warshal(vector<vector<int>> costs) {
      for (auto& x : costs) {
        for (auto& y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    vector<vector<int>> arcs = costs;
    for (int k = 0; k < arcs.size(); ++k) {
        for (int i = 0; i < arcs.size(); ++i) {
            for (int j = 0; j < arcs.size(); ++j) {
                if (arcs[i][k] != INT_MAX && arcs[k][j] != INT_MAX && arcs[i][j] > arcs[i][k] + arcs[k][j]) {
                    arcs[i][j] = arcs[i][k] + arcs[k][j];
                }
            }
        }
    }
    for (auto& x : arcs) {
        for (auto& y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    vector<vector<int>> costs = {
        {0, 3, 1, 2 , INT_MAX},
        {3, 0, 1, INT_MAX, INT_MAX},
        {1, 1, 0, 3,10},
        {2, INT_MAX, 3, 0, 2},
        {INT_MAX, INT_MAX, 10, 2 , 0},
    };
    floyd_warshal(costs);
}