/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
    void preorderTraversalHelper_recursion(Node* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        result.push_back(root->val);
        for (auto& child : root->children) {
            preorderTraversalHelper_recursion(child, result);
        }
    }

    void preorderTraversalHelper_loop(Node* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderTraversalHelper_recursion(root, result);
        return result;
    }
};
// @lc code=end
