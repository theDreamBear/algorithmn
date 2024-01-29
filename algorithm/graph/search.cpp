#include "graph.cpp"
#include <numeric>
#include <stack>
#include <vector>

class UF {
private:
    vector<int> parent;
public:
    UF(int v):parent(v) {
        iota(parent.begin(), parent.end(), 0);
    }

    // 返回节点的根节点
    int find(int v) {
        // 对于第二层的节点不需要调整
        if (parent[v] == parent[parent[v]]) {
            return parent[v];
        }
        return parent[v] = find(parent[v]);
    }

    void merge(int v, int w) {
        int pv = find(v);
        int pw = find(w);
        if (pv == pw) {
            return;
        }
        parent[pw] = pv;
    }

    bool connected(int v, int w) {
        return find(v) == find(w);
    }
};


class GSearch {
 private:
    UF uf;
public:
    GSearch(Graph& g): uf(g.V()) {
        for (int v = 0; v < g.V(); v++) {
            for (int w : g.adj(v)) {
                uf.merge(v, w);
            }
        }
    }

    bool connected(int v, int w) {
        return uf.connected(v, w);
    }
};

class DfsGSearch {
private:
    void dfs(int v) {
        marked[v] = 1;
        for (const auto w : g.adj(v)) {
            if (!marked[w]) {
                dfs(w);
            }
        }
    }

public:
    const Graph& g;
    vector<int> marked;

    DfsGSearch(const Graph& g):g(g), marked(g.V()){
        for (int i = 0; i < g.V(); i++) {
            if (!marked[i]) {
                dfs(i);
            }
        }
    }

};

class DfsDSearch {
private:
    void dfs(int v) {
        marked[v] = 1;
        for (const auto w : g.adj(v)) {
            if (!marked[w]) {
                dfs(w);
            }
        }
    }

public:
    const Digraph& g;
    vector<int> marked;

    DfsDSearch(const Digraph& g):g(g), marked(g.V()){
        for (int i = 0; i < g.V(); i++) {
            if (!marked[i]) {
                dfs(i);
            }
        }
    }
};

class CycleSearch{
private:
    const Digraph& g;
    vector<int> marked;
    vector<int> onStack;
    vector<int> edgeTo;

    vector<int> cycle;

    void dfs(int v) {
        marked[v] = 1;
        onStack[v] = 1;
        for (const auto w : g.adj(v)) {
            if (hasCycle()) {
                return;
            }
            if (!marked[w]) {
                // 设置root
                edgeTo[w] = v;
                dfs(w);
                continue;
            }
            // 有环
            if (onStack[w]) {
                cycle.push_back(w);
                for (int x = v; x != w; x = edgeTo[x]) {
                    cycle.push_back(x);
                }
                cycle.push_back(w);
                reverse(cycle.begin(), cycle.end());
                return;
            }
        }
        onStack[v] = 0;
    }
public:
    CycleSearch(const Digraph& g):g(g), marked(g.V()), onStack(g.V()), edgeTo(g.V()){
        for (int v = 0; v < g.V(); v++) {
            if (!marked[v]) {
                dfs(v);
            }
        }
    }

    bool hasCycle() const {
        return !cycle.empty();
    }

    const vector<int>& getCycle() const{
        return cycle;
    }
};

class TologySearch {
private:
    const Digraph& g;
    vector<int> marked;
    vector<int> onStack;
    stack<int> revese_post;
    bool has_loop = false;

    void dfs(int v) {
        marked[v] = 1;
        onStack[v] = 1;
        for (const int w : g.adj(v)) {
            if (!marked[w]) {
                dfs(w);
                continue;
            }
            if (onStack[w]) {
                has_loop = true;
                return;
            }
        }
        revese_post.push(v);
        onStack[v] = 0;
    }
public:
    TologySearch(const Digraph& g):g(g), marked(g.V()), onStack(g.V()) {
        has_loop = false;
        for (int v = 0; !has_loop && v < g.V(); v++) {
            if (!marked[v]) {
                dfs(v);
            }
        }
    }

    vector<int> topologySort() {
        vector<int> ans;
        if (has_loop) {
            return ans;
        }
        while (!revese_post.empty()) {
            ans.push_back(revese_post.top());
            revese_post.pop();
        }
        return ans;
    }
};
