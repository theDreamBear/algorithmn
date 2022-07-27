/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

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
class Solution {
public:
    vector<TreeNode*> generateTreesHelper(int low, int high) {
        if (low > high) {
            return {nullptr};
        }
        if (low == high) {
            return {new TreeNode(low)};
        }
        vector<TreeNode*> ans;
        for (int i = low; i <= high; i++) {
            auto left = generateTreesHelper(low, i - 1);
            auto right = generateTreesHelper(i + 1, high);
            for (auto l : left) {
                for (auto r : right) {
                    auto root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }
};
// @lc code=end

