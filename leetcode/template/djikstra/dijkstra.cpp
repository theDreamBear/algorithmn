#include<iostream>

#include<vector>
#include <climits>
#include<queue>
#include<algorithm>

using namespace std;

static constexpr int INTMAX = 0x7ffffff;
static constexpr int UNREACHABLE = -1;

int dijkstra_common(vector<vector<int>> costs, int start, int end) {
    int vCount = costs.size();
    vector<int> distance(vCount, INTMAX);
    vector<int> visit(vCount, 0);
    distance[start] = 0;

    for (int ct = costs.size(); ct > 0; --ct) {
        int v = -1;
        // 找到最小距离的点  这个地方可以优化因为我们去掉以访问节点
        for (int i = 0; i < vCount; ++i) {
            // 未访问节点
            if (!visit[i]) {
                if (v == -1 || distance[i] < distance[v]) {
                    v = i;
                }
            }
        }
        visit[v] = 1;
        // 更新
        if (distance[v] == INTMAX) {
            break;
        }
        // 有哪些边我们也可以存起来
        for (int i = 0; i < vCount; ++i) {
            if (costs[v][i] != UNREACHABLE) {
                distance[i] = min(distance[i], costs[v][i] + distance[v]);
            }
        }
    }
    return distance[end];
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
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        for (int i = 0; i < costs[v].size(); ++i) {
            if (costs[v][i] != INT_MAX && distance[i] > distance[v] + costs[v][i]) {
                distance[i] = distance[v] + costs[v][i];
                minHeap.push({distance[i], i});
            }
        }
    }
    return distance[end];
}


void floyd(vector<vector<int>> costs) {
      for (auto& x : costs) {
        for (auto& y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    vector<vector<int>> arcs(costs.size(), vector<int>(costs[0].size(), INT_MAX));
    for (int k = 0; k < costs.size(); ++k) {
        for (int i = 0; i < costs.size(); ++i) {
            for (int j = 0; j < costs.size(); ++j) {
                if (costs[i][k] != INT_MAX && costs[k][j] != INT_MAX && arcs[i][j] > costs[i][k] + costs[k][j]) {
                    arcs[i][j] = costs[i][k] + costs[k][j];
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
        {1, 1, 3, 10},
        {2, INT_MAX, 3, 0, 2},
        {INT_MAX, INT_MAX, 10, 2 , 0},
    };
    floyd(costs);
}