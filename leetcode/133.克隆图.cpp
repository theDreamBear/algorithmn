/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Node {
 public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
    /*
        dfs 定义返回 node 节点的深拷贝节点指针
    */
    Node* dfs(Node* node, unordered_map<int, Node*>& existed) {
        // 边界判断 如果
        if (node == NULL) {
            return NULL;
        }
        // 若深拷贝节点指针存在
        if (existed.count(node->val) > 0) {
            return existed[node->val];
        }
        // 不存在则创建, 并深拷贝其邻居节点
        // 具体逻辑地方
        Node* n = new Node(node->val);
        existed[n->val] = n;
        //

        // 迭代地方
        for (auto& nei : node->neighbors) {
            // 深拷贝邻居节点
            n->neighbors.push_back(dfs(nei, existed));
        }
        return n;
    }

    Node* cloneGraph_dfs(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        unordered_map<int, Node*> hash;
        return dfs(node, hash);
    }

    /*
        bfs , 初始化
    */
     Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        unordered_map<int, Node*> hash;
        queue<Node*> q;

        // 初始化
        q.push(node);
        Node* root = new Node(node->val);
        hash[root->val] = root;

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            Node* n = hash[cur->val];
            for (auto& nei : cur->neighbors) {
                // 生成新的节点指针的位置
                if (hash.count(nei->val) == 0) {
                    q.push(nei);
                    Node* temp = new Node(nei->val);
                    hash[temp->val] = temp;
                }
                n->neighbors.push_back(hash[nei->val]);
            }
        }
        return root;
    }
};
// @lc code=end
