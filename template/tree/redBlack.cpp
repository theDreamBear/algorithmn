// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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

template<typename Key, typename Value>
class RedBlackTree {
public:
    enum class Color {
        Red = 0,
        Black = 1,
    };

    struct Node {
        Key key;
        Value value;
        Node *left, *right;
        Color color;
        int ct;

        Node(const Key &key = Key{}, const Value &value = Value{}, Color color = Color::Black, int ct = 1,
             Node *left = {},
             Node *right = {}) : key(key), value(value), color(color), ct(ct), left(left), right(right) {
        }
    };

    Node *root = nullptr;

    RedBlackTree() {
        root = nullptr;
    }

    bool isRed(Node *h) {
        return h and h->color == Color::Red;
    }

    int size(Node *h) {
        return h ? h->ct : 0;
    }

    int tall() {
        return tall(root);
    }

    int tall(Node *node) {
        if (!node) return 0;
        return ::max(tall(node->left), tall(node->right)) + 1;
    }


    void update(Node *h) {
        if (!h) return;
        h->ct = 1 + size(h->left) + size(h->right);
    }

    Node *rotateLeft(Node *h) {
        Node *x = h->right;
        h->right = x->left;
        x->left = h;

        x->color = h->color;
        h->color = Color::Red;

        update(h);
        update(x);
        return x;
    }

    Node *rotateRight(Node *h) {
        Node *x = h->left;
        h->left = x->right;
        x->right = h;

        x->color = h->color;
        h->color = Color::Red;

        update(h);
        update(x);
        return x;
    }

    void flipColor(Node *h) {
        h->color = h->color == Color::Red ? Color::Black : Color::Red;
        h->left->color = h->left->color == Color::Red ? Color::Black : Color::Red;
        h->right->color = h->right->color == Color::Red ? Color::Black : Color::Red;
    }

    void put(const Key &key, const Value &value) {
        root = put(root, key, value);
        root->color = Color::Black;
    }

    Node *put(Node *h, const Key &key, const Value &value) {
        if (!h) {
            return new Node(key, value, Color::Red, 1);
        }
        if (key < h->key) h->left = put(h->left, key, value);
        else if (key > h->key) h->right = put(h->right, key, value);
        else {
            // 设置值
            h->value = value;
        }
        // 旋转
        if (isRed(h->right) and !isRed(h->left)) h = rotateLeft(h);
        if (isRed(h->left) and isRed(h->left->left)) { h = rotateRight(h); }
        if (isRed(h->left) and isRed(h->right)) flipColor(h);

        update(h);
        return h;
    }

    Node *find(int val) {
        Node *h = root;
        while (h) {
            if (h->value == val) break;
            if (h->value > val) h = h->left;
            else h = h->right;
        }
        return h;
    }

    Node *min(Node *h) {
        while (h and h->left) {
            h = h->left;
        }
        return h;
    }

    Node *max(Node *h) {
        while (h and h->right) {
            h = h->right;
        }
        return h;
    }

    void deleteMin() {
        if (!root) return;
        //保证每次处理的时候节点都是红的
        if (!isRed(root->left) and !isRed(root->right)) {
            root->color = Color::Red;
        }
        root = deleteMin(root);
        if (!root) {
            root->color = Color::Black;
        }
    }

    Node *moveRedLeft(Node *h) {
        assert(h->right);
        // 将左右都变成红的, 根变黑, 但是黑高不变
        flipColor(h);
        // 因为h的左子树是黑的, 那么必然存在右子也是黑的, 那么向右子借一个红的, 如果有的话
        if (isRed(h->right->left)) {
            // 右旋红色变成了 h->right->right 的位置
            // h 右和 右右都变成红的了
            h->right = rotateRight(h->right);
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

    Node *moveRedRight(Node *h) {
        // 左右变红, h 变黑
        flipColor(h);
        if (isRed(h->left->left)) {
            // 移动左边一个红到右边
            h = rotateRight(h);
            //从左二红 变成 左右各一红
        } else {
            // 左右变红, h 变黑,  右边有红色可用
        }
        return h;
    }

    Node *balance(Node *h) {
        if (isRed(h->right)) h = rotateLeft(h);
        if (h->left and isRed(h->left) and isRed(h->left->left)) h = rotateRight(h);
        if (isRed(h->left) and isRed(h->right)) flipColor(h);
        update(h);
        return h;
    }

    Node *deleteMin(Node *h) {
        if (!h->left) return nullptr;
        // 孩子是二节点
        if (h->left and !isRed(h->left) and !isRed(h->left->left)) {
            // 需要从右孩子借
            h = moveRedLeft(h);
        }
        h->left = deleteMin(h->left);
        return balance(h);
    }

    // 每次操作的h的颜色一定是红的
    Node *deleteNode(Node *h, const Key &key) {
        if (!h) return nullptr;
        if (h->key > key) {
            // 去左子树查看, 子节点是 2节点
            if (h->left and !isRed(h->left) and !isRed(h->left->left)) {
                // 存在左黑代表一定存在右节点
                h = moveRedLeft(h);
            }
            h->left = deleteNode(h->left, key);
        } else {
            // 左边有红的, 偷过来
            if (isRed(h->left)) h = rotateRight(h); // b->r
            if (h->key == key and h->right == nullptr) {
                return nullptr;
            }
            // 右子树看看, 右子树是 2节点, 从右左偷一个过来
            // b->r
            if (h->right and !isRed(h->right) and !isRed(h->right->left)) {
                h = moveRedRight(h);
            }
            if (h->key == key) {
                // 找到了
                Node *mm = min(h->right);
                h->key = mm->key;
                h->value = mm->value;
                h->right = deleteMin(h->right);
            } else {
                h->right = deleteNode(h->right, key);
            }
        }
        return balance(h);
    }

    void deleteNode(const Key &key) {
        if (!root) return;
        if (!isRed(root->left) and !isRed(root->right)) {
            root->color = Color::Red;
        }
        root = deleteNode(root, key);
        if (root) root->color = Color::Black;
    }

    // kth小
    Node *find_by_rank(int rnk) {
        auto find = [&](auto &&dfs, Node *h, int rk)-> Node * {
            if (rk <= 0 or !h or size(h) < rk) return nullptr;
            if (size(h->left) >= rk) return dfs(dfs, h->left, rk);
            if (size(h->left) + 1 == rk) return h;
            return dfs(dfs, h->right, rk - size(h->left) - 1);
        };
        return find(find, root, rnk);
    }

    Node *find_by_key(const Key &key) {
        auto find = [&](auto &&dfs, Node *h)-> Node * {
            if (!h) return nullptr;
            if (h->key == key) return h;
            if (h->key > key) return dfs(dfs, h->left);
            return dfs(dfs, h->right);
        };
        return find(find, root);
    }

    vector<pair<Key, Value> > traversal() {
        vector<pair<Key, Value> > res;
        auto dfs = [&](auto &&dfs, Node *h) {
            if (!h) return;
            dfs(dfs, h->left);
            res.emplace_back(h->key, h->value);
            dfs(dfs, h->right);
        };
        dfs(dfs, root);
        return res;
    }

    // >= key的
    Node *lower_bound(const Key &key) {
        auto find = [&](auto &&dfs, Node *h)-> Node * {
            if (!h) return nullptr;
            if (h->key == key) return h;
            if (key < h->key) {
                auto x = dfs(dfs, h->left);
                if (x) return x;
                return h;
            }
            return dfs(dfs, h->right);
        };
        return find(find, root);
    }

    // > key的
    Node *upper_bound(const Key &key) {
        auto find = [&](auto &&dfs, Node *h)-> Node * {
            if (!h) return nullptr;
            if (h->key > key) {
                auto x = dfs(dfs, h->left);
                if (x) {
                    return x;
                }
                return h;
            }
            return dfs(dfs, h->right);
        };
        return find(find, root);
    }

    bool isBalance(Node *h) {
        if (!h) return true;
        auto post = [](auto &&dfs, Node *node)-> tuple<int, int, int> {
            if (!node) {
                // 最小值, 最大值, hei
                return {INT_MAX, INT_MIN, 0};
            }
            auto [lm, lx, lh] = dfs(dfs, node->left);
            auto [rm, rx, rh] = dfs(dfs, node->right);
            if (node->key <= lx or node->key >= rm or lh != rh) return {INT_MIN, INT_MAX, 0};
            return {::min(node->key, lm), ::max(node->key, rx), lh + (node->color == Color::Black)};
        };
        auto [rm, rx, rh] = post(post, h);
        return rh > 0;
    }
};

void test_balance() {
    for (int j = 0; j < 100; ++j) {
        vector<int> ans = random_vec(1000, 10000000);
        RedBlackTree<int, int> tree;
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
        RedBlackTree<int, int> tree;
        for (auto v: ans) {
            tree.put(v, v);
        }
        auto rks = tree.traversal();
        for (int i = -100; i < tree.root->ct + 100; i++) {
            if (i < 0) {
                auto x = tree.find_by_rank(i + 1);
                if (x != nullptr) {
                    throw logic_error("bad rank1");
                    return;
                }
            } else {
                auto x = tree.find_by_rank(i + 1);
                if (x != nullptr) {
                    if (x->key != rks[i].first or x->value != rks[i].second) {
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
        RedBlackTree<int, int> tree;
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
        RedBlackTree<int, int> tree;
        for (auto v: ans) {
            tree.put(v, v);
        }
        auto rks = tree.traversal();
        sort(rks.begin(), rks.end());
        for (auto x: rks) {
            auto l1 = tree.lower_bound(x.first);
            if (!l1 or l1->key != x.first) {
                throw logic_error("bad lower_bound");
            }
            auto l2 = tree.upper_bound(x.second);
            auto it = upper_bound(rks.begin(), rks.end(), x) - rks.begin();
            if (it != rks.size() and rks[it].first != l2->key) {
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
