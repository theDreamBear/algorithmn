#include<iostream>

#include<vector>
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

#include<queue>

// 使用优先级队列优化
int dijkstra(vector<vector<int>> costs, int start, int end) {
    int vCount = costs.size();
    vector<int> distance(vCount, INTMAX);
    vector<int> visit(vCount, 0);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > heap;
    
}


int main() {
    vector<int> res;
}