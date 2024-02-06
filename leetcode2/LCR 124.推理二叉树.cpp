/*
 * @lc app=leetcode.cn id=LCR 124 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 124] 推理二叉树
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder, int l1, int h1, int l2, int h2) {
        if (l1 > h1 ||l2 > h2) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[l1]);
        int p = find(inorder.begin() + l2, inorder.begin() + h2 +1, preorder[l1]) - inorder.begin() - l2;
        root->left = deduceTree(preorder, inorder, l1 + 1,  l1 + p, l2, l2 + p - 1);
        root->right = deduceTree(preorder, inorder, l1 + 1 + p, h1, l2 + p + 1, h2);
        return root;
    }

    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        return deduceTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

