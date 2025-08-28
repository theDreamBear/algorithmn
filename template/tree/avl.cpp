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
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
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
using namespace std;


struct Node {
    int val;
    Node* left, *right, *p;

    Node(int val = 0, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr): val(val), left(left), right(right), p(p) {}
};

Node* minnum(Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

Node* maxnum(Node* node) {
    while (node->right) {
        node = node->right;
    }
    return node;
}

// 后
Node* successor(Node* node) {
    if (node->right) {
        return minnum(node->right);
    }
    // 右祖先,
    Node* pp = node->p;
    Node* x = node;
    while (!x and pp->right == x) {
        x = pp;
        pp = pp->p;
    }
    return x;
}

// 前驱
Node* preduccessor(Node* node) {
    if (node->left) {
        return maxnum(node->left);
    }
    Node* pp = node->p;
    Node* x = node;
    while (!x and pp->left == x) {
        x = pp;
        pp = pp->p;
    }
    return x;
}

class AVL {
private:
    Node* root = nullptr;

public:
    Node* insert(int val) {
        if (!root) {
            root = new Node(val);
            return root;
        }
        Node* fa = nullptr, *cur = root;
        while (cur) {
            //
            if (cur->val == val) {
                return cur;
            }
            fa = cur;
            if (cur->val < val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        Node* node = new Node(val);
        node->p = fa;
        if (val < fa->val) {
            fa->left = node;
        } else {
            fa->right = node;
        }
        return node;
    }

    Node* find(int val) {
        if (!root) {
            return root;
        }
        Node *cur = root;
        while (cur) {
            if (cur->val == val) {
                return cur;
            }
            if (cur->val < val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return nullptr;
    }

    void remove(int val) {
        if (!root) return;
        Node *cur = root;
        while (cur) {
            if (cur->val == val) {
                break;
            }
            if (cur->val < val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        // 没找到
        if (!cur) return;
        Node* fa = cur->p;
        // ok1 oo1
        if (!cur->left and !cur->right) {
            // 只有一个节点且为根
            if (!fa) {
                delete root;
                root = nullptr;
                return;
            }
            if (fa->left == cur) {
                fa->left = nullptr;
            } else {
                fa->right = nullptr;
            }
            delete cur;
            return;
        }
        // 有右节点 ok2 oo2
        if (!cur->left) {
            if (!fa) {
                root = cur->right;
                root->p = nullptr;
                delete cur;
                return;
            }
            if (fa->left == cur) {
                fa->left = cur->right;
            } else {
                fa->right = cur->right;
            }
            cur->right->p = fa;
            delete cur;
            return;
        }
        // 有左 ok3 oo3
        if (!cur->right) {
            if (!fa) {
                root = cur->left;
                root->p = nullptr;
                delete cur;
                return;
            }
            if (fa->left == cur) {
                fa->left = cur->left;
            } else {
                fa->right = cur->left;
            }
            cur->left->p = fa;
            delete cur;
            return;
        }
        // 左右均不为空 oo4
        Node* mx = minnum(cur->right);
        Node* pp = mx->p;
        if (pp->left == mx) {
            pp->left = mx->right;
        } else {
            pp->right = mx->right;
        }
        if (mx->right) {
            mx->right->p = pp;
        }
        if (fa) {
            if (fa->left == cur) {
                fa->left = mx;
            } else {
                fa->right = mx;
            }
            mx->p = fa;
        } else {
            mx->p = nullptr;
            root = mx;
        }
        mx->left = cur->left;
        //if (cur->left) {
        cur->left->p = mx;
        //}
        mx->right = cur->right;
        if (cur->right) {
            cur->right->p = mx;
        }
        delete cur;
    }

    void makeTree(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            insert(nums[i]);
        }
    }

    void traverse(Node* node, vector<int>& ans) {
        if (nullptr == node) {
            return;
        }
        traverse(node->left, ans);
        ans.push_back(node->val);
        traverse(node->right, ans);
    }

    bool isSorted() {
        vector<int> ans;
        traverse(root, ans);
        return is_sorted(ans.begin(), ans.end());
    }
};

vector<int> random_vec(int n, int maxv = 100000) {
    mt19937 rng(random_device{}());
    uniform_int_distribution<> dis(0, maxv);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        ans.push_back(dis(rng));
    }
    return ans;
}

// 性能堪忧, 但是随机数据情况下, 还可以
int main() {
    for (int j = 0; j < 1000; ++j) {
        vector<int> ans = random_vec(1000);
        AVL avl;
        avl.makeTree(ans);
        shuffle(ans.begin(), ans.end(), mt19937{random_device{}()});
        for (const int an : ans) {
            avl.remove(an);
            if (!avl.isSorted()) {
                cout << "bad" << endl;
                return 0;
            }
        }
    }
    cout << "ok" << endl;
}