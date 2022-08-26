#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <chrono>

using namespace std;

class Graph {
public:
    virtual void add(int from, int to) {
        nodes[from].adjacent.push_back(to);
        nodes[to].adjacent.push_back(from);
    }
    struct Vertex {
        vector<int> adjacent;
    };

    vector<int> know;
    vector<int> id;
    int count = 0;

    void dfs(int node) {
        if (know[node]) {
            return;
        }
        preOrder.push_back(node);
        know[node] = 1;
        id[node] = count;
        for (auto adj: nodes[node].adjacent) {
            if (know[adj]) {
                continue;
            }
            dfs(adj);
        }
        postOrder.push_back(node);
    }

    vector<Vertex> nodes;
public:
    vector<int> preOrder;
    vector<int> postOrder;
    vector<int> reversePostOrder;

    Graph() {}

    void traversal() {
        for (int i = 0; i < nodes.size(); i++) {
            dfs(i);
            ++count;
        }
        reversePostOrder = postOrder;
        std::reverse(reversePostOrder.begin(), reversePostOrder.end());
    }

     void traversal(int n, vector<vector<int>> edges) {
        nodes = vector<Vertex>(n);
        know = vector<int>(n);
        id = vector<int>(n, -1);
        for (auto &vec: edges) {
            add(vec[0], vec[1]);
        }
        for (int i = 0; i < nodes.size(); i++) {
            dfs(i);
            ++count;
        }
        reversePostOrder = postOrder;
        std::reverse(reversePostOrder.begin(), reversePostOrder.end());
    }

    bool connected(int v, int w) {
        return id[v] != -1 && id[v] == id[w];
    }
};

class Digraph : public Graph {
public:
    Graph *reverse() {
        Graph *g = new Digraph;
        vector<Vertex> new_nodes(nodes.size());
        for (int i = 0; i < nodes.size(); i++) {
            for (auto adj: nodes[i].adjacent) {
                new_nodes[adj].adjacent.push_back(i);
            }
        }
        g->nodes = new_nodes;
        g->know = vector<int>(nodes.size());
        g->id = vector<int>(nodes.size(), -1);
        return g;
    }

    void connet_traversal(int n, vector<vector<int>> edges) {
        nodes = vector<Vertex>(n);
        know = vector<int>(n);
        id = vector<int>(n, -1);
        for (auto &vec: edges) {
            add(vec[0], vec[1]);
        }

        Graph *x = this->reverse();
        x->traversal();
        for (auto i: x->reversePostOrder) {
            if (know[i]) {
                continue;
            }
            dfs(i);
            ++count;
        }
    }

public:
    void add(int from, int to) override {
        nodes[from].adjacent.push_back(to);
    }
};

int main() {
    vector<vector<int>> edg = {{0, 1},
                               {1, 2},
                               {3, 4},
                               {4, 5},
                               {5, 4},
                               {3, 2},
                               {3, 7},
                               {7, 5},
                               {2, 6},
                               {6, 0},
    };
    Digraph* g = new Digraph;
    g->connet_traversal(8, edg);
    for (int i = 0 ; i < 10; i++) {
        for (int node = 0; node < 8; node++) {
            if (g->id[node] == i) {
                cout << node << " ";
            }
        }
        cout << endl;
    }
}




