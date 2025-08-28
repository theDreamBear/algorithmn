// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <climits>
#include <cstdlib>
#include <ctime>
#if __cplusplus >= 201103L
// #include <cstdalign>
#endif
// C++
#include <algorithm>
#include <functional>
#include <ostream>
#include <stdexcept>
#include <utility>
#include <vector>
#if __cplusplus >= 201103L
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#endif
#include <iostream>
using namespace std;

vector<int> random_vec(int n, int maxv = 100000) {
    mt19937 rng(random_device{}());
    uniform_int_distribution<> dis(0, maxv);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        ans.push_back(dis(rng));
    }
    return ans;
}

enum class Color {
    Red = 0,
    Black = 1,
};

constexpr int mx = 1e6;

#define Key int
#define Value int

struct Node {
    Key key;
    Value value;
    int left, right;
    Color color;
    int ct;

    Node(const Key &key = Key{}, const Value &value = Value{}, Color color = Color::Black, int ct = 1,
         int left = {},
         int right = {}) : key(key), value(value), color(color), ct(ct), left(left), right(right) {
    }
} nodes[mx];

int id = 0;

int new_node(const Key& key, const Value& value) {
    int x = ++id;
    nodes[x].key = key;
    nodes[x].value = value;
    nodes[x].left = nodes[x].right = 0;
    nodes[x].color = Color::Red;
    nodes[x].ct = 1;
    return x;
}

#define get(id) nodes[id]
#define getl(id) get(id).left
#define getr(id) get(id).right

#define getll(id) get(get(id).left).left
#define getlr(id) get(get(id).left).right

#define getlrr(id) get(get(id).right).right
#define getrl(id) get(get(id).right).left

#define getc(id) get(id).color
#define gett(id) get(id).ct
#define getk(id) get(id).key
#define getv(id) get(id).value

bool isRed(int h) {
    return h and getc(h) == Color::Red;
}

int size(int h) {
    return h ? gett(h) : 0;
}

int tall(int h) {
    if (!h) return 0;
    return ::max(tall(getl(h)), tall(getr(h))) + 1;
}


void update(int h) {
    if (!h) return;
    get(h).ct = 1 + size(getl(h)) + size(getr(h));
}

int rotateLeft(int h) {
    int x = getr(h);
    getr(h) = getl(x);
    getl(x) = h;
    getc(x) = getc(h);
    getc(h) = Color::Red;
    update(h);
    update(x);
    return x;
}

int rotateRight(int h) {
    int x = getl(h);
    getl(h) = getr(x);
    getr(x) = h;
    getc(x) = getc(h);
    getc(h) = Color::Red;
    update(h);
    update(x);
    return x;
}

void flipColor(int h) {
    getc(h) = getc(h) == Color::Red ? Color::Black : Color::Red;
    getc(getl(h)) = getc(getl(h)) == Color::Red ? Color::Black : Color::Red;
    getc(getr(h)) = getc(getr(h)) == Color::Red ? Color::Black : Color::Red;
}

auto init = []()-> int {
    id = 0;
    return 0;
}();

class RedBlackTree {
public:
    int root = 0;

    int tall() const {
        return ::tall(root);
    }

    RedBlackTree() {
        root = 0;
    }

    void put(const Key &key, const Value &value) {
        root = put(root, key, value);
        getc(root) = Color::Black;
    }

    int put(int h, const Key &key, const Value &value) {
        if (!h) {
            return new_node(key, value);
        }
        if (key < getk(h)) getl(h) = put(getl(h), key, value);
        else if (key > getk(h)) getr(h) = put(getr(h), key, value);
        else {
            // 设置值
            getv(h) = value;
        }
        // 旋转
        if (isRed(getr(h)) and !isRed(getl(h))) h = rotateLeft(h);
        if (isRed(getl(h)) and isRed(getll(h))) { h = rotateRight(h); }
        if (isRed(getl(h)) and isRed(getr(h))) flipColor(h);
        update(h);
        return h;
    }

    int find(int val) {
        int h = root;
        while (h) {
            if (getv(h) == val) break;
            if (getv(h) > val) h = getl(h);
            else h = getr(h);
        }
        return h;
    }

    int min(int h) {
        while (h and getl(h)) {
            h = getl(h);
        }
        return h;
    }

    int max(int h) {
        while (h and getr(h)) {
            h = getr(h);
        }
        return h;
    }

    void deleteMin() {
        if (!root) return;
        //保证每次处理的时候节点都是红的
        if (!isRed(getl(root)) and !isRed(getr(root))) {
            getc(root) = Color::Red;
        }
        root = deleteMin(root);
        if (!root) {
            getc(root) = Color::Black;
        }
    }

    int moveRedLeft(int h) {
        assert(getr(h));
        // 将左右都变成红的, 根变黑, 但是黑高不变
        flipColor(h);
        // 因为h的左子树是黑的, 那么必然存在右子也是黑的, 那么向右子借一个红的, 如果有的话
        if (isRed(getrl(h))) {
            // 右旋红色变成了 h->right->right 的位置
            // h 右和 右右都变成红的了
            getr(h) = rotateRight(getr(h));
            // 左旋后, h变成黑色, 单存在左红, 和右红
            // 这时候相当于 h 变成了临时的4节点, 后续balance会修复
            h = rotateLeft(h);
            // 从左 1 红 右 2红 变成 左 2 红 右一红
        } else {
            // 因为颜色反转, h变成了3节点
        }
        // b->r->r
        // b->r
        return h;
    }

    int moveRedRight(int h) {
        // 左右变红, h 变黑
        flipColor(h);
        if (isRed(getll(h))) {
            // 移动左边一个红到右边
            h = rotateRight(h);
            //从左二红 变成 左右各一红
        } else {
            // 左右变红, h 变黑,  右边有红色可用
        }
        return h;
    }

    int balance(int h) {
        if (isRed(getr(h))) h = rotateLeft(h);
        if (getl(h) and isRed(getl(h)) and isRed(getll(h))) h = rotateRight(h);
        if (isRed(getl(h)) and isRed(getr(h))) flipColor(h);
        update(h);
        return h;
    }

    int deleteMin(int h) {
        if (!getl(h)) return 0;
        // 孩子是二节点
        if (getl(h) and !isRed(getl(h)) and !isRed(getll(h))) {
            // 需要从右孩子借
            h = moveRedLeft(h);
        }
        getl(h) = deleteMin(getl(h));
        return balance(h);
    }

    // 每次操作的h的颜色一定是红的
    int deleteNode(int h, const Key &key) {
        if (!h) return 0;
        if (getk(h) > key) {
            // 去左子树查看, 子节点是 2节点
            if (getl(h) and !isRed(getl(h)) and !isRed(getll(h))) {
                // 存在左黑代表一定存在右节点
                h = moveRedLeft(h);
            }
            getl(h) = deleteNode(getl(h), key);
        } else {
            // 左边有红的, 偷过来
            if (isRed(getl(h))) h = rotateRight(h); // b->r
            if (getk(h) == key and getr(h) == 0) {
                return 0;
            }
            // 右子树看看, 右子树是 2节点, 从右左偷一个过来
            // b->r
            if (getr(h) and !isRed(getr(h)) and !isRed(getrl(h))) {
                h = moveRedRight(h);
            }
            if (getk(h) == key) {
                // 找到了
                int mm = min(getr(h));
                getk(h) = getk(mm);
                getv(h) = getv(mm);
                getr(h) = deleteMin(getr(h));
            } else {
                getr(h) = deleteNode(getr(h), key);
            }
        }
        return balance(h);
    }

    void deleteNode(const Key &key) {
        if (!root) return;
        if (!isRed(getl(root)) and !isRed(getr(root))) {
            getc(root) = Color::Red;
        }
        root = deleteNode(root, key);
        if (root) getc(root) = Color::Black;
    }

    // kth小
    int find_by_rank(int rnk) {
        auto find = [&](auto &&dfs, int h, int rk)-> int {
            if (rk <= 0 or !h or size(h) < rk) return 0;
            if (size(getl(h)) >= rk) return dfs(dfs, getl(h), rk);
            if (size(getl(h)) + 1 == rk) return h;
            return dfs(dfs, getr(h), rk - size(getl(h)) - 1);
        };
        return find(find, root, rnk);
    }

    int find_by_key(const Key &key) {
        auto find = [&](auto &&dfs, int h)-> int{
            if (!h) return 0;
            if (getk(h) == key) return h;
            if (getk(h) > key) return dfs(dfs, getl(h));
            return dfs(dfs, getr(h));
        };
        return find(find, root);
    }

    bool contains(const Key &key) {
        return find_by_key(key) != 0;
    }

    // >= key的
    int lower_bound(const Key &key) {
        auto find = [&](auto &&dfs, int h)-> int {
            if (!h) return 0;
            auto mx = max(getl(h));
            if (mx and getk(mx) >= key) return dfs(dfs, getl(h));
            if (getk(h) == key) return h;
            mx = max(getr(h));
            if (mx and getk(mx) >= key) return dfs(dfs, getr(h));
            return 0;
        };
        return find(find, root);
    }

    vector<pair<Key, Value> > traversal() {
        vector<pair<Key, Value> > res;
        auto dfs = [&](auto &&dfs, int h) {
            if (!h) return;
            dfs(dfs, getl(h));
            res.emplace_back(getk(h), getv(h));
            dfs(dfs, getr(h));
        };
        dfs(dfs, root);
        return res;
    }

    // > key的
    int upper_bound(const Key &key) {
        auto find = [&](auto &&dfs, int h) {
            if (!h) return 0;
            auto mx = max(getl(h));
            if (mx and getk(mx) > key) return dfs(dfs, getl(h));
            if (getk(h) > key) return h;
            mx = max(getr(h));
            if (mx and getk(mx) > key) return dfs(dfs, getr(h));
            return 0;
        };
        return find(find, root);
    }

    bool isBalance(int h) {
        if (!h) return true;
        auto post = [](auto &&dfs, int node)-> tuple<int, int, int> {
            if (!node) {
                // 最小值, 最大值, hei
                return {INT_MAX, INT_MIN, 0};
            }
            auto [lm, lx, lh] = dfs(dfs, getl(node));
            auto [rm, rx, rh] = dfs(dfs, getr(node));
            if (getk(node) <= lx or getk(node) >= rm or lh != rh) return {INT_MIN, INT_MAX, 0};
            return {::min(getk(node), lm), ::max(getk(node), rx), lh + (getc(node) == Color::Black)};
        };
        auto [rm, rx, rh] = post(post, h);
        return rh > 0;
    }
};

void test_balance() {
    for (int j = 0; j < 100; ++j) {
        vector<int> ans = random_vec(1000, 10000000);
        RedBlackTree tree;
        for (auto v: ans) {
            tree.put(v, v);
        }
        if (!tree.isBalance(tree.root)) {
            cout << "bad balanced" << endl;
            throw;
        }
        //cout << tree.root->ct / pow(2, tree.tall(tree.root)) << endl;
    }
    cout << "balanced" << endl;
}

void test_rank() {
    for (int j = 0; j < 100; ++j) {
        vector<int> ans = random_vec(1000, 10000000);
        RedBlackTree tree;
        for (auto v: ans) {
            tree.put(v, v);
        }
        auto rks = tree.traversal();
        for (int i = -100; i < gett(tree.root) + 100; i++) {
            if (i < 0) {
                auto x = tree.find_by_rank(i + 1);
                if (x != 0) {
                    throw logic_error("bad rank1");
                    return;
                }
            } else {
                auto x = tree.find_by_rank(i + 1);
                if (x != 0) {
                    if (getk(x) != rks[i].first or getv(x) != rks[i].second) {
                        throw logic_error("bad rank2");
                    }
                }
            }
        }
    }
    cout << "ranked" << endl;
}

void test_find() {
    for (int j = 0; j < 100; ++j) {
        vector<int> ans = random_vec(1000, 10000000);
        RedBlackTree tree;
        for (auto v: ans) {
            tree.put(v, v);
        }
        auto rks = tree.traversal();
        sort(rks.begin(), rks.end());
        for (auto x: rks) {
            if (!tree.find_by_key(x.first)) {
                throw logic_error("bad find_by_key");
            }
        }
    }
    cout << "found" << endl;
}

void test_binary_bound() {
    for (int j = 0; j < 100; ++j) {
        vector<int> ans = random_vec(1000, 10000000);
        RedBlackTree tree;
        for (auto v: ans) {
            tree.put(v, v);
        }
        auto rks = tree.traversal();
        sort(rks.begin(), rks.end());
        for (auto x: rks) {
            auto l1 = tree.lower_bound(x.first);
            if (!l1) {
                throw logic_error("bad lower_bound");
            }
            auto l2 = tree.upper_bound(x.second);
            auto it = upper_bound(rks.begin(), rks.end(), x) - rks.begin();
            if (it != rks.size() and rks[it].first != getk(l2)) {
                throw logic_error("bad upper_bound");
            }
        }
    }
    cout << "binaried" << endl;
}

int main() {
    test_rank();
    test_find();
    test_balance();
    test_binary_bound();
}
