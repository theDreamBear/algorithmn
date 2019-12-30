#include<iostream>
#include<vector>
#include <stack>
using namespace std;

//#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void makeTree(TreeNode* &root) {
    TreeNode*r = new TreeNode(3);
    root = r;

    TreeNode* node = new TreeNode(1);
    root->left = node;
    
    TreeNode* node1 = new TreeNode(2);
    root->left->right = node1;

    TreeNode* node2 = new TreeNode(5);
    root->right = node2;

    TreeNode* node3  = new TreeNode(4);

    root->right->left = node3;
}

// 先序遍历 递归
vector<int> preorderTraversalDivideAndConquer(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    ans.push_back(root->val);
    auto left = preorderTraversalDivideAndConquer(root->left);
    copy(left.begin(), left.end(), back_inserter(ans));
    left = preorderTraversalDivideAndConquer(root->right);
    copy(left.begin(), left.end(), back_inserter(ans));
    return ans;
}

void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 先序遍历非递归
vector<int> preorderTraversalNonDiversion(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    // 已访问节点
    stack<TreeNode*> stack;
    // 当前待访问节点
    TreeNode* cur = root;
    while(cur != NULL || !stack.empty()) {
        while( cur != NULL ) {
            ans.push_back(cur->val);
            stack.push(cur);
            cur = cur->left;
        }
        if (cur == NULL) {
            cur = stack.top();
            stack.pop();
            cur = cur->right;
        }
    }
    return ans;
}

vector<int> preorderTraversalLeftCut(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        // 已访问节点
        stack<TreeNode*> stack;
        // 上次已访问节点
        TreeNode* cur = root;
        ans.push_back(cur->val);
        stack.push(cur);
        while(!stack.empty()) {
            gg:
            while( true ) {
                if (cur->left != NULL) {
                    cur = cur -> left;
                    ans.push_back(cur->val);
                    stack.push(cur);
                } else {
                    break;
                }
            }
            while (!stack.empty()) {
                cur = stack.top();
                stack.pop();
                if (cur->right != NULL) {
                    cur = cur->right;
                    ans.push_back(cur->val);
                    stack.push(cur);
                    goto gg;
                }
            }
            break;
        }
        return ans;
}


int main() {
    TreeNode* root;
    makeTree(root);
    preorderTraversal(root);
}