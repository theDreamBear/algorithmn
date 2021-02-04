/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
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
    Node* dfs1(Node* node, unordered_map<int, Node*>& hash) {
        if (node == NULL || hash.count(node->val) > 0) {
            return NULL;
        }
        Node* root = new Node(node->val);
        hash[root->val] = root;
        // dfs
        for (auto& nei : node->neighbors) {
            if (hash.count(nei->val) == 0) {
                Node* temp = new Node(nei->val);
                hash[temp->val] = temp;
                root->neighbors.push_back(hash[nei->val]);
                dfs1(nei, hash);
            } else {
                root->neighbors.push_back(hash[nei->val]);
            }
        }
        return root;
    }

    Node* newNode(Node* node, unordered_map<int, Node*>& existed) {
        Node* newNode = new Node(node->val);
        existed[newNode->val] = newNode;
        return newNode;
    }

    bool compare(Node* node, Node* newNode) {
        if (node->val != newNode->val || node == newNode || node->neighbors.size() != newNode->neighbors.size()) {
           // cout << "no" << endl;
           // cout << node->val << "  " << newNode->val << endl;
           // cout << node << "   " << newNode << endl;
           // cout << node->neighbors.size() << "    " << newNode->neighbors.size() << endl;
            return false;
        }
        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (!compare(node->neighbors[i], newNode->neighbors[i])) {
                //cout << node->neighbors[i]->val << "   " << newNode->neighbors[i]->val << endl;
                return false;
            }
        }
        //cout << "yes" << endl;
        return true;
    }

    Node* dfs(Node* node, unordered_map<int, Node*>& existed) {
        if (node == NULL || existed.count(node->val) > 0) {
            cout << "ok" << endl;
            return NULL;
        }
        Node* n = newNode(node, existed);
        for (auto& nei : node->neighbors) {
            cout << "push: " << nei->val << endl;
            if (existed.count(nei->val) == 0) {
                Node* temp = new Node(nei->val);
                n->neighbors.push_back(temp);
                dfs(nei, existed);
            } else {
                n->neighbors.push_back(existed[nei->val]);
            }

        }
        return n;
    }


    Node* cloneGraph(Node* node) {
        if (node ==  NULL) {
            return NULL;
        }
        unordered_map<int, Node*> hash;
        Node* r =  dfs(node, hash);
         if (compare(node, r)) {
            cout << "yes" << endl;
        }
        cout <<"res1111  " <<  r << endl;
        return r;
    }
};
// @lc code=end

