/*
 * @lc app=leetcode.cn id=432 lang=cpp
 * @lcpr version=30204
 *
 * [432] 全 O(1) 的数据结构
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <random>
// @lcpr-template-end
// @lc code=start
/*
设计思路文档
1. 同样次数的字符串放在一起构成结构A, 且需要能O(1)取其中一个
    // O(1) 存储, 这需要用到哈希表
    // 我们可以封装一个结构A, 然后内部封装哈希表

2. 不同结构A 按照次数从小到大排序, 用 head, tail 来 O(1)访问第一个min, max
    当某一个结构A变成空以后, 需要访问其前后节点来删除
    可以发现需要用 list 这种双向链表存储结构A
*/

// list使用注意点
// prev(begin()) UB
// next(end()) UB
class A {
public:
    unordered_set<string> strs;
    int cnt = 1;

    A(int cnt = 1):cnt(cnt) {}

    void insert(const string& str) {
        strs.insert(str);
    }

    void erase(const string& str) {
        strs.erase(str);
    }

    int size() const {
        return strs.size();
    }

    string one_str() const{
        assert(strs.size() > 0);
        return *strs.begin();
    }
};

class Cache {
public:
    list<A> data;
    unordered_map<string, list<A>::iterator> nodes;

    void inc(const string& key) {
        // 不存在
        if (!nodes.count(key)) {
            // 判断是否需要插入
            if (data.empty() or data.front().cnt > 1) {
                data.push_front(A(1));
            }
            data.front().insert(key);
            nodes[key] = data.begin();
            return;
        }
        // 存在的话
        auto it = nodes[key];
        auto nxt = next(it);
        // 添加 最后一个 或者不相连
        if (nxt == data.end() or it->cnt + 1 < nxt->cnt) {
            nxt = data.insert(nxt, A(it->cnt + 1));
        }
        nxt->insert(key);
        nodes[key] = nxt;

        // 删除
        it->erase(key);
        // 若链表为空则删除
        if (it->size() == 0) {
            data.erase(it);
        }
    }

    void dec(const string& key) {
        if (!nodes.count(key)) return;
        auto it = nodes[key];
        // 若次数> 1
        if (it->cnt > 1) {
            list<A>::iterator pre;
            if (it == data.begin()) {
                // 没有前一个节点，直接插入到最前面
                pre = data.insert(it, A(it->cnt - 1));
            } else {
                pre = prev(it);
                if (pre->cnt < it->cnt - 1) {
                    pre = data.insert(it, A(it->cnt - 1));
                }
            }
            pre->insert(key);
            nodes[key] = pre;
        } else {
            // 减少到0了
            nodes.erase(key);
        }
        // 删除
        it->erase(key);
        // 若链表为空则删除
        if (it->size() == 0) {
            data.erase(it);
        }
    }

    string getMaxKey() const {
        return data.size() ? data.rbegin()->one_str(): "";
    }

    string getMinKey() const {
        return data.size() ? data.begin()->one_str(): "";
    }
};


class AllOne {
public:
    Cache cache;

    AllOne() {

    }

    void inc(string key) {
        cache.inc(key);
    }

    void dec(string key) {
        cache.dec(key);
    }

    string getMaxKey() {
        return cache.getMaxKey();
    }

    string getMinKey() {
        return cache.getMinKey();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end



