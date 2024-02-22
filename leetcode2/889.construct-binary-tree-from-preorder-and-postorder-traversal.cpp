/*
 * @lc app=leetcode.cn id=889 lang=cpp
 * @lcpr version=30117
 *
 * [889] 根据前序和后序遍历构造二叉树
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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
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
    TreeNode* constructFromPrePost1(vector<int>& preorder, vector<int>& postorder, int l1, int h1, int l2, int h2) {
        if (l1 > h1 || l2 > h2) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[l1]);
        if (l1 == h1) {
            return root;
        }
        // 找左子树
        unordered_map<int, int> hash;
        int ct = 0, len = 0;
        l1++;
        do {
            if (++hash[preorder[l1 + len]] == 1) {
                ++ct;
            }
            if (--hash[postorder[l2 + len]] == 0) {
                --ct;
            }
            ++len;
        } while (ct != 0);
        root->left = constructFromPrePost1(preorder, postorder, l1, l1 + len - 1, l2, l2 + len - 1);
        root->right = constructFromPrePost1(preorder, postorder, l1 + len, h1, l2 + len, h2 - 1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return constructFromPrePost1(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */

