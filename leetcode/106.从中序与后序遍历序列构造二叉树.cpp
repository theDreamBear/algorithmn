/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(int low1, int high1, int low2, int high2,const vector<int>& inorder, const vector<int>& postorder) {
        if (low1 > high1) {
            return NULL;
        }
        if (low1 == high1) {
            return new TreeNode(inorder[low1]);
        }
        int rootVal = postorder[high2];
        int rootIdx = low1;
        for (; rootIdx <= high1;) {
            if (inorder[rootIdx] != rootVal) {
                ++rootIdx;
            } else {
                break;
            }
        }
        TreeNode* root = new TreeNode(rootVal);
        int rightLen = high1 - rootIdx;
        root->left = dfs(low1, rootIdx - 1, low2, high2 - rightLen - 1, inorder, postorder);
        root->right = dfs(rootIdx + 1, high1,  high2 - rightLen - 1, high2 - 1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
};
// @lc code=end

int main() {
    vector<int> inorder = {1,2,3,4};
    vector<int> postorder = {3,2,4,1};
    Solution{}.buildTree(inorder, postorder);
    cout << "je" << endl;
}