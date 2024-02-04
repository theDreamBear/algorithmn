#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Graph {
 private:
    int vnt, ent;
    vector<vector<int>> data;
public:
    Graph(int v):vnt(v), ent(0), data(v){}

    void addEdge(int v, int w) {
        // 自环
        if (v == w) {
            return;
        }
        // 平行边
        if (hasEdge(v, w)) {
            return;
        }
        data[v].push_back(w);
        data[w].push_back(v);
        ent++;
    }

    const vector<int>& adj(int v) const{
        assert(v < data.size());
        return data[v];
    }

    int V() const{
        return vnt;
    }

    int E() const{
        return ent;
    }

    bool hasEdge(int v, int w) const{
        if (v >= vnt || w >= vnt) {
            return false;
        }
        return find(adj(v).begin(), adj(v).end(), w) != adj(v).end();
    }

};

class Digraph {
private:
    vector<vector<int>> data;
     int vnt, ent;
public:
    Digraph(int v):data(v){
        vnt = v;
        ent = 0;
    }

    void addEdge(int v, int w) {
        data[v].push_back(w);
        ent++;
    }

    const vector<int>& adj(int v) const {
        assert(v < data.size());
        return data[v];
    }

    int V() const {
        return vnt;
    }

    int E() const {
        return ent;
    }

    Digraph reverse() const {
        Digraph ng(V());
        for (int v = 0; v < V(); v++) {
            for (const auto w : adj(v)) {
                ng.addEdge(w, v);
            }
        }
        return ng;
    }
};

class WeightEdge {
private:
    int from, to;
    double weight;

public:
    WeightEdge(int from = -1, int to = -1, double weight = -1):from(from), to(to), weight(weight){}

    int From() {
        return from;
    }

    int To() {
        return to;
    }

    int Weight() {
        return weight;
    }
};

class WeightEdgeDigraph {
public:
    vector<vector<WeightEdge>> data;
    int v;

    WeightEdgeDigraph(int v):data(v), v(v){}

    int V() const {
        return v;
    }

    const vector<WeightEdge>& adj(int v) const {
        return data[v];
    }

    void addEdge(int from, int to, double weight) {
        data[from].emplace_back(from, to, weight);
    }
};