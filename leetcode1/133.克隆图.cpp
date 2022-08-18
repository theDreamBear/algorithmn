/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

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
    unordered_map<int, Node*> exist;
public:

    Node *cloneGraph(Node *node) {
        if (nullptr == node) {
            return nullptr;
        }
        if (exist.count(node->val)) {
            return exist[node->val];
        }
        Node* root = new Node(node->val);
        exist[node->val] = root;
        for (auto child :  node->neighbors) {
            auto nx = cloneGraph(child);
            if (nx) {
                root->neighbors.push_back(nx);
            }
        }
        return root;
    }
};
// @lc code=end

