/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (61.19%)
 * Likes:    189
 * Dislikes: 0
 * Total Accepted:    22.2K
 * Total Submissions: 36.1K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */

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

    /**
     *  1. 先序遍历
     * 
     * **/
    void preorderVisit(TreeNode* node, vector<string>& ans, string s) {
        if (node == NULL) {
            return;
        }
        if (s == "") {
            s.append(to_string(node->val));
        } else {
            s.append("->");
            s.append(to_string(node->val));
        }
        if (node->left == NULL && node->right == NULL) {
            ans.push_back(s);
            return;
        }
        preorderVisit(node->left, ans, s);
        preorderVisit(node->right, ans, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) {
            return ans;
        }
        string s = "";
        preorderVisit(root, ans, s);
        return ans;
    }
};
// @lc code=end

