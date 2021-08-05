/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class MyCircularQueue1 {
private:
    vector<int> vec;
    int sz;
    int front; // 队头
    int rear;  // 下一个可插入的位置
    bool full;

public:
    MyCircularQueue1(int k) : vec(k), sz(k) {
        front = 0;
        rear = 0;
        full = false;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        vec[rear] = value;
        rear = (rear + 1) % sz;
        if (rear == front) {
            full = true;
        }
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % sz;
        full = false;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return vec[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int pos = (rear + sz - 1) % sz;
        return vec[pos];
    }

    bool isEmpty() {
        return !full && rear == front;
    }

    bool isFull() {
        return full;
    }
};

/*
    不取尾和取尾有不同的写法
*/
class MyCircularQueue {
private:
    struct ListNode {
        int val;
        ListNode *next;
    };

    ListNode *front;
    ListNode *rear;
    bool empty;

public:
    MyCircularQueue(int k) {
        front = new ListNode;
        rear = front;
        for (int i = 0; i < k - 1; i++) {
            ListNode *node = new ListNode;
            rear->next = node;
            rear = node;
        }
        rear->next = front;
        rear = front;
        empty = true;
    }

    ~MyCircularQueue() {
        ListNode* node = this->rear;
        node->next = nullptr;
        node = this->front;
        while (node) {
            ListNode* next = node->next;
            delete node;
            node = next;
        }
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            empty = false;
        } else {
            rear = rear->next;
        }
        rear->val = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            empty = true;
            return true;
        }
        front = front->next;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return front->val;
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return rear->val;
    }

    bool isEmpty() {
        return empty;
    }

    bool isFull() {
        return !empty && rear->next == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

