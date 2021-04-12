/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    先存起来再说, 空间换时间
    空间复杂度高
*/
class BSTIterator1 {
private:
    vector<int> nodes;
    int index;

    void inorderTraversal(TreeNode* root) {
        if (!root) {
            return;
        }
        inorderTraversal(root->left);
        nodes.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    BSTIterator1(TreeNode* root) {
        index = 0;
        inorderTraversal(root);
    }

    int next() {
        if (hasNext()) {
            return nodes[index++];
        }
        return -1;
    }

    bool hasNext() {
        return index < nodes.size();
    }
};


class BSTIterator {
private:
    vector<TreeNode*> nodes;
    TreeNode* cur;

    int inorderTraversal() {
        while (cur || !nodes.empty()) {
            while (cur) {
                nodes.push_back(cur);
                cur = cur->left;
            }
            cur = nodes.back();
            int nextVal = cur->val;
            nodes.pop_back();
            cur = cur->right;
            return nextVal;
        }
        return -1;
    }
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }

    int next() {
        if (hasNext()) {
            return inorderTraversal();
        }
        return -1;
    }

    bool hasNext() {
        return cur || !nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

