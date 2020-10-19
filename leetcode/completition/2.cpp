#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<string> ans;
int add_new = 0;
void handRotate(string& s, int l, int r) {
    for (; l < r; ++l, --r) {
        swap(s[l], s[r]);
    }
}

void rotate(string s, int b) {
    // 任何字符串最多旋转当前长度，就能得到所有情况
    for (int i = 0; i < s.size(); ++i) {
        // 右旋b 位
        handRotate(s, 0, s.size() - b - 1);
        handRotate(s, s.size() - b, s.size() - 1);
        handRotate(s, 0, s.size() - 1);

        if (ans.find(s) == ans.end()) {
            ++add_new;
            ans.insert(s);
        } else {
            // 当前已入队列，后面的就不用操作了
            break;
        }
    }
}

void addAll(string s, int a) {
    for (int j = 0; j <= max(a, 10 - a); ++j) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] += a;
            if (s[i] > '9') {
                s[i] -= 10;
            }
        }
        if (ans.find(s) == ans.end()) {
            ++add_new;
            ans.insert(s);
        } else {
            break;
        }
    }
}

string findLexSmallestString(string s, int a, int b) {
    ans.clear();
    ans.insert(s);
    while (true) {
        add_new = 0;
        for (auto x : ans) {
            // 旋转
            rotate(x, b);
        }
        for (auto x : ans) {
            addAll(x, a);
        }
        if (add_new == 0) {
            break;
        }
    }
    return *ans.begin();
}

struct te {
    string s;
    int a, b;
    string r;
};

int main() {
    vector<te> r = {{
        {"5525", 9, 2, "2050"},
        {"74", 5, 1, "24"},
        {"0011", 4, 2, "0011"},
        {"43987654", 7, 3, "00553311"},
    }};
    for (int i = 0; i < r.size(); ++i) {
        auto x = findLexSmallestString(r[i].s, r[i].a, r[i].b);
        if (r[i].r != x) {
            cout << r[i].s << " " << r[i].a << " " << r[i].b << " " << x
                 << endl;
        }
    }
}
