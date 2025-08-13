/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 * @lcpr version=30204
 *
 * [1206] 设计跳表
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
mt19937 mt(random_device{}());
uniform_real_distribution<double> u(0, 1);

int get_len() {
    int len = 1;
    while (len < 32 and u(mt) < 0.25) {
        len++;
    }
    return len;
}

struct SkipListNode {
    int val;
    vector<SkipListNode*> forward;

    SkipListNode(int val = -1): val(val), forward(get_len(), nullptr) {}

    int size() const {
        return forward.size();
    }
};

class Skiplist {
private:
    vector<SkipListNode*> find_pre(int num) {
        vector<SkipListNode*> update(maxsz);
        SkipListNode* cur = &head;
        for (int i = maxsz - 1; i >= 0; i--) {
            while (cur->forward[i] and cur->forward[i]->val < num) {
                cur = cur->forward[i];
            }
            update[i] = cur;
        }
        return update;
    }

public:
    SkipListNode head;
    int maxsz;

    Skiplist() {
        maxsz = head.size();
    }

    bool search(int target) {
        SkipListNode* cur = &head;
        for (int i = maxsz - 1; i >= 0; i--) {
            while (cur->forward[i] and cur->forward[i]->val <= target) {
                if (cur->forward[i]->val == target) return true;
                cur = cur->forward[i];
            }
        }
        return false;
    }

    void add(int num) {
        SkipListNode* nd = new SkipListNode(num);
        if (nd->size() > maxsz) {
            head.forward.resize(nd->size());
            maxsz = nd->size();
        }
        vector<SkipListNode*> update(find_pre(num));
        for (int i = 0; i < nd->size(); i++) {
            nd->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = nd;
        }
    }

    bool erase(int num) {
        vector<SkipListNode*> update(find_pre(num));
        bool flag = false;
        // 删除
        for (int i = 0; i < maxsz; i++) {
            if (update[i]->forward[i] and update[i]->forward[i]->val == num) {
                flag = true;
                update[i]->forward[i] = update[i]->forward[i]->forward[i];
            }
        }
        return flag;
    }
};

struct NodeItem;
struct Node {
    Node* prev, *next;
    NodeItem* owner;

    Node(int rk = 0,  NodeItem* owner = nullptr):prev(nullptr), next(nullptr), owner(owner){}
};

struct NodeItem {
public:
    int val = 0;
    vector<Node*> forward;

    NodeItem(int val = -1): val(val), forward(get_len(), nullptr) {
        for (int i = 0; i < forward.size(); i++) {
            forward[i] = new Node(i, this);
        }
    }

    int size() const {
        return forward.size();
    }
};

class Skiplist_Dlist {
public:
    NodeItem head;
    int maxsz;

    Skiplist_Dlist() {
        maxsz = head.size();
        for (int i = 0; i < maxsz; i++) {
            head.forward[i]->next = head.forward[i];
            head.forward[i]->prev = head.forward[i];
        }
    }

    bool search(int target) {
        Node* node = head.forward.back();
        int idx = maxsz - 1;
        for (; idx >= 0; ) {
            Node* next = node->next;
            if (next->owner != &head) {
                if (next->owner->val < target) {
                    node = next;
                    continue;
                } else if (next->owner->val == target) {
                    return true;
                }
            }
            if (idx > 0) {
                node = node->owner->forward[idx - 1];
            }
            idx--;
        }
        return false;
    }

    void add(int num) {
        NodeItem* nd = new NodeItem(num);
        if (nd->size() > maxsz) {
            head.forward.resize(nd->size());
            for (int i = maxsz; i < nd->size(); i++) {
                head.forward[i] = new Node(i, &head);
                head.forward[i]->next = head.forward[i];
                head.forward[i]->prev = head.forward[i];
            }
            maxsz = nd->size();
        }
        vector<Node*> update(maxsz);
        Node* node = head.forward.back();
        int idx = maxsz - 1;
        for (; idx >= 0; ) {
            Node* next = node->next;
            if (next->owner != &head and next->owner->val < num) {
                node = next;
                continue;
            }
            update[idx] = node;
            if (idx > 0) {
                node = node->owner->forward[idx - 1];
            }
            idx--;
        }
        // 插入
        for (int i = 0; i < nd->size(); i++) {
            nd->forward[i]->next = update[i]->next;
            update[i]->next->prev = nd->forward[i];
            update[i]->next = nd->forward[i];
            nd->forward[i]->prev = update[i];
        }

    }

    bool erase(int num) {
        vector<Node*> update(maxsz);
        Node* node = head.forward.back();
        int idx = maxsz - 1;
        for (; idx >= 0; ) {
            Node* next = node->next;
            if (next->owner != &head and next->owner->val < num) {
                node = next;
                continue;
            }
            update[idx] = node;
            if (idx > 0) {
                node = node->owner->forward[idx - 1];
            }
            idx--;
        }
        bool flag = false;
        // 删除
        for (int i = 0; i < maxsz; i++) {
            auto nxt = update[i]->next;
            if (nxt->owner != &head) {
                // 删除
                if (nxt->owner->val == num) {
                    flag = true;
                    update[i]->next = nxt->next;
                    nxt->next->prev = update[i];
                }
            }
        }
        return flag;
    }
};
/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end



