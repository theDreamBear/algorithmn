/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    /*
        类似后续遍历
    */
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int max_len = 0;
        for (auto node : root->children) {
            int len = maxDepth(node);
            if (len > max_len) {
                max_len = len;
            }
        }
        return max_len + 1;
    }
};
// @lc code=end

