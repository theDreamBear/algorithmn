#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <stack>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct Vertex {
    vector<Edge> adjacent;
    int dis = INT_MAX;
    int closed = 0;
    int pre = -1;
};

class Graph {
    vector<Vertex> nodes;
    int n;

public:
    Graph(int n, vector<vector<int>> &edges) : nodes(n) {
        this->n = n;
        for (auto &vec: edges) {
            int from = vec[0];
            int to = vec[1];
            int weight = vec[2];
            nodes[from].adjacent.push_back({.to = to, .weight = weight});
        }
    }

    [[nodiscard]] int Vex() const {
        return n;
    }

    vector<Edge> &getEdges(int v) {
        return nodes[v].adjacent;
    }


    void setClosed(int v) {
        nodes[v].closed = 1;
    }

    [[nodiscard]] bool isClosed(int v) const {
        return nodes[v].closed;
    }

    void setDistance(int v, int d) {
        nodes[v].dis = d;
    }

    int getDistance(int v) {
        return nodes[v].dis;
    }

    void setPre(int v, int pre) {
        nodes[v].pre = pre;
    }

    int getPre(int v) {
        return nodes[v].pre;
    }
};


class QAbs {
public:
    virtual void enQ(int id) = 0;

    virtual int deQ() = 0;

    virtual bool empty() = 0;
};

class DfsQ : public QAbs {
private:
    stack<int> q;

public:
    void enQ(int id) override {
        q.push(id);
    }

    int deQ() override {
        int id = q.top();
        q.pop();
        return id;
    }

    bool empty() override {
        return q.empty();
    }
};

class BfsQ : public QAbs {
private:
    queue<int> q;
public:
    void enQ(int id) override {
        q.push(id);
    }

    int deQ() override {
        int id = q.front();
        q.pop();
        return id;
    }

    bool empty() override {
        return q.empty();
    }
};

enum class Order {
    BFS = 0,
    DFS = 1,
};

class TraversalAbs {
private:
    Graph *g;
    vector<bool> known;
    QAbs *q;

public:
    TraversalAbs(Graph *g, Order order) : g(g), known(g->Vex()) {
        if (order == Order::BFS) {
            q = new BfsQ;
        } else {
            q = new DfsQ;
        }
    }

    void traversal(int v) {
        known[v] = true;
        q->enQ(v);
        while (!q->empty()) {
            int id = q->deQ();
            // 先序
            cout << id << "\t";
            for (auto w: g->getEdges(id)) {
                int to = w.to;
                if (known[to]) {
                    continue;
                }
                known[to] = true;
                q->enQ(to);
            }
        }
        cout << endl;
    }
};


int main() {
    vector<vector<int>> data = {
            {0, 1, 2},
            {1, 2, 2},
            {2, 3, 1},
            {3, 4, 2},
            {0, 4, 3},
    };
    auto g = new Graph(5, data);

    // bfs 遍历
    TraversalAbs btr(g, Order::BFS);
    btr.traversal(0);

    // dfs 遍历
    TraversalAbs dtr(g, Order::DFS);
    dtr.traversal(0);
}