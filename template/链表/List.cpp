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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

namespace My_List {
    /*
    1. 链表长度: size
    2. 翻转链表: reverse
    3. kth
    4. kth pre
    5. left mid
    6. right mid
    7. 合并两个有序链表
    */
    int size(ListNode *node) {
        if (!node) return 0;
        ListNode *cur = node;
        int len = 0;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        return len;
    }

    // 翻转链表
    ListNode *reverse(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        ListNode *pre = nullptr, *cur = node;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    // 查找第k个链表节点
    ListNode *find_kth(ListNode *node, int k) {
        ListNode *cur = node;
        while (--k and cur) {
            cur = cur->next;
        }
        assert(k == 0);
        return cur;
    }

    ListNode *find_kth_pre(ListNode *node, int k) {
        // k = 1, 头结点没有pre
        assert(k > 1);
        return find_kth(node, k - 1);
    }

    // 查找右mid
    ListNode *find_right_mid(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        ListNode *slow = node, *fast = node;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        return slow;
    }

    ListNode *find_right_mid2(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        int sz = size(node);
        return find_kth(node, sz / 2 + 1);
    }

    // 查找左mid
    ListNode *find_left_mid(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        ListNode *slow = node, *fast = node->next;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        return slow;
    }

    ListNode *find_left_mid2(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        int sz = size(node);
        return find_kth(node, (sz + 1) / 2);
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 or l2) {
            if (!l1) {
                tail->next = l2;
                break;
            }
            if (!l2) {
                tail->next = l1;
                break;
            }
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        return dummy.next;
    }

    ListNode* splitKList(ListNode* node, int k) {
        assert(k > 0);
        if (!node) return node;
        ListNode* cur = node;
        while (--k) {
            cur = cur->next;
        }
        ListNode* nh = cur->next;
        cur->next = nullptr;
        return nh;
    }
    

    struct List {
        ListNode *head = nullptr, *tail = nullptr;
    };

    List NodeToList(ListNode *node) {
        List list;
        list.head = node;
        ListNode *cur = node;
        while (cur->next) {
            cur = cur->next;
        }
        list.tail = cur;
        return list;
    }


    List reverseList(List &list) {
        if (!list.head) return list;
        List tmp = list;
        reverse(list.head);
        swap(tmp.head, tmp.tail);
        return tmp;
    }


};

using namespace My_List;

vector<int> random_vec() {
    mt19937 mt(random_device{}());
    uniform_int_distribution<int> u(1, 1000);
    int n = u(mt);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = u(mt);
    }
    return a;
}


ListNode *makeList(const vector<int> &a) {
    ListNode dummy;
    ListNode *tail = &dummy;
    for (auto v: a) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// 通过
void test_mid() {
    for (int i = 0; i < 1000; i++) {
        auto head = makeList(random_vec());
        if (find_left_mid(head) != find_left_mid2(head)) {
            cout << "bad" << endl;
            return;
        }
        if (find_right_mid(head) != find_right_mid2(head)) {
            cout << "bad2" << endl;
            return;
        }
    }
    cout << "success" << endl;
}

int main() {
    test_mid();
}
