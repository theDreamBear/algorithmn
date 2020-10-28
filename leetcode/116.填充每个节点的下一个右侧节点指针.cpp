/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* tail[100];
    // dfs
    void dfs(int i, Node* root) {
        if (root == NULL) {
            return;
        }
        if (tail[i] == NULL) {
            tail[i] = root;
        } else {
            tail[i]->next = root;
            tail[i] = root;
        }
        dfs(i + 1, root->left);
        dfs(i + 1, root->right);
    }

    Node* connect(Node* root) {
        fill(tail, tail + 100, nullptr);
        dfs(0, root);
        return root;
    }

    /*
    方法二， 二叉树的层次遍历
    */
};
// @lc code=end

