#include <iostream>
#include <map>
#include <vector>
using namespace std;

constexpr static int MAX = 10000;

vector<vector<int>> dp(10000, vector<int>(10000, 0));

int getIndex(int i) { return i - 1; }

int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void calculateConnected(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i == j) {
                dp[i - 1][j - 1] = i;
            } else {
                int c = gcd(i, j);
                dp[i - 1][j - 1] = c;
            }
        }
    }
}

int maxparent(int n, int x) { return n - n % x; }

struct unionQuery {
    vector<int> _data;

    unionQuery(int n) : _data(n + 1, 0) {
        for (int i = 0; i < _data.size(); ++i) {
            _data[i] = i;
        }
    }

    int findParent(int i) {
        if (_data[i] == i) {
            return i;
        }
        _data[i] = findParent(_data[i]);
        return _data[i];
    }

    void merge(int i, int j) {
        int pi = findParent(i);
        int pj = findParent(j);
        _data[pi] = pj;
    }

    void init(int n, int threshold) {
        for (int i = threshold + 1; i <= n; ++i) {
            int mp = maxparent(n, i);
            for (int j = i; j <= n; j += i) {
                merge(mp, j);
            }
        }
    }
};

/*
存在间接相连的情况
threshold = 3
9 - 18 - 24 - 16
*/
vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
    vector<bool> ans(queries.size(), false);
    if (threshold == 0) {
        ans = vector<bool>(queries.size(), true);
        return ans;
    }
    unionQuery uq(n);
    uq.init(n, threshold);
    for (int i = 0; i < queries.size(); ++i) {
        int l = uq.findParent(queries[i][0]);
        int r = uq.findParent(queries[i][1]);
        if (l == r) {
            ans[i] = true;
        }
    }
    return ans;
}

struct te {
    vector<vector<int>> s;
    vector<bool> r;
};

int main() {
    vector<te> r = {
        {{{16, 9}}, {true}},
        {{{18, 20}}, {true}},
    };
    for (int i = 0; i < r.size(); ++i) {
        if (r[i].r != areConnected(26, 3, r[i].s)) {
            cout << i << endl;
        }
    }
}