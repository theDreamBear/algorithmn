#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

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
    int n{};

   private:
    Graph() = default;

   public:
    Graph(int n, vector<vector<int>>& edges) : nodes(n) {
        this->n = n;
        for (auto& vec : edges) {
            int from = vec[0];
            int to = vec[1];
            int weight = vec[2];
            nodes[from].adjacent.push_back({.to = to, .weight = weight});
        }
    }

    [[nodiscard]] int Vex() const { return n; }

    const vector<Edge>& getEdges(int v) const { return nodes[v].adjacent; }

    void setClosed(int v) { nodes[v].closed = 1; }

    [[nodiscard]] bool isClosed(int v) const { return nodes[v].closed; }

    void setDistance(int v, int d) { nodes[v].dis = d; }

    int getDistance(int v) { return nodes[v].dis; }

    void setPre(int v, int pre) { nodes[v].pre = pre; }

    int getPre(int v) { return nodes[v].pre; }

    Graph reverse() const {
        Graph g;
        g.n = this->n;
        g.nodes = vector<Vertex>(n);
        for (int i = 0; i < n; i++) {
            for (const auto& e : this->getEdges(i)) {
                int to = e.to;
                int weight = e.weight;
                g.nodes[to].adjacent.push_back({.to = i, .weight = weight});
            }
        }
        return g;
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
    void enQ(int id) override { q.push(id); }

    int deQ() override {
        int id = q.top();
        q.pop();
        return id;
    }

    bool empty() override { return q.empty(); }
};

class BfsQ : public QAbs {
   private:
    queue<int> q;

   public:
    void enQ(int id) override { q.push(id); }

    int deQ() override {
        int id = q.front();
        q.pop();
        return id;
    }

    bool empty() override { return q.empty(); }
};

enum class Order {
    BFS = 0,
    DFS = 1,
};

class TraversalAbs {
   public:
    Graph* g;
    vector<bool> known;
    QAbs* q;

    virtual void pre(int v) { cout << v << "\t"; }

    virtual void after(int v) {}

    virtual void afterOneTraversal() { cout << endl; }

    virtual void afterTraversal() {}

   public:
    TraversalAbs(Graph* g, Order order) : g(g), known(g->Vex()) {
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
            pre(id);
            for (auto w : g->getEdges(id)) {
                int to = w.to;
                if (known[to]) {
                    continue;
                }
                g->setPre(to, id);
                known[to] = true;
                q->enQ(to);
            }
            after(id);
        }
        afterOneTraversal();
    }

    void traversal() {
        for (int i = 0; i < g->Vex(); i++) {
            if (known[i]) {
                continue;
            }
            traversal(i);
        }
        afterTraversal();
    }
};

class DfsFirstTopology : public TraversalAbs {
   public:
    explicit DfsFirstTopology(Graph* g) : TraversalAbs(g, Order::DFS) {}

   private:
    stack<int> st;
    stack<int> ans;

    void pre(int v) override {
        // 入栈
        st.push(v);
    }

    void after(int v) override {}

   public:
    void afterTraversal() override {
        while (!ans.empty()) {
            cout << ans.top() << "\t";
            ans.pop();
        }
        cout << endl;
    }

    void afterOneTraversal() override {
        while (!st.empty()) {
            ans.push(st.top());
            st.pop();
        }
    }
};

int main() {
    vector<vector<int>> data = {
        {0, 1, 2}, {1, 2, 2}, {2, 3, 1}, {3, 4, 2}, {0, 4, 3},
    };
    auto g = new Graph(5, data);

    auto rg = g->reverse();

    // bfs 遍历
    TraversalAbs btr(g, Order::BFS);
    btr.traversal(0);

    // dfs 遍历
    TraversalAbs dtr(g, Order::DFS);
    dtr.traversal(0);

    // 拓扑排序
    auto df = new DfsFirstTopology(&rg);
    df->traversal();
}