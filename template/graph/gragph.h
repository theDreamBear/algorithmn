#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
   protected:
    virtual void add(int from, int to) {
        nodes[from].adjacent.push_back(to);
        nodes[to].adjacent.push_back(from);
    }

    struct Vertex {
        vector<int> adjacent;
    };
    vector<Vertex> nodes;
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
        for (auto adj : nodes[node].adjacent) {
            if (know[adj]) {
                continue;
            }
            dfs(adj);
        }
        postOrder.push_back(node);
    }

   public:
    vector<int> preOrder;
    vector<int> postOrder;
    vector<int> reversePostOrder;

    Graph() {}

    void traversal(int n, vector<vector<int>> edges) {
        nodes.resize(n);
        know.resize(n);
        id.resize(n);
        for (auto& vec : edges) {
            add(vec[0], vec[1]);
        }
        vector<int> know(nodes.size());
        vector<int> ans;
        for (int i = 0; i < nodes.size(); i++) {
            dfs(i);
        }
        reversePostOrder = postOrder;
        std::reverse(reversePostOrder.begin(), reversePostOrder.end());
    }

    void reverse() {
        vector<Vertex> new_nodes(nodes.size());
        for (int i = 0; i < nodes.size(); i++) {
            for (auto adj : nodes[i].adjacent) {
                new_nodes[adj].adjacent.push_back(i);
            }
        }
        nodes = new_nodes;
    }
};

class Digraph : public Graph {
   public:
   protected:
    void add(int from, int to) override { nodes[from].adjacent.push_back(to); }
};

int main() {
    vector<vector<int>> edg = {{0, 1}, {2, 1}, {1, 4}, {3, 4}, {4, 5}};
    auto g = new Digraph;
    g->traversal(6, edg);
    for (auto v : g->preOrder) {
        cout << v << "\t";
    }
    cout << endl;

    for (auto v : g->postOrder) {
        cout << v << "\t";
    }
    cout << endl;

    for (auto v : g->reversePostOrder) {
        cout << v << "\t";
    }
    cout << endl;
}
