/*
 * @lc app=leetcode.cn id=LCR 054 lang=cpp
 * @lcpr version=30120
 *
 * [LCR 054] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST_loop(TreeNode* root) {
        int sum = 0;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            cur->val += sum;
            sum = cur->val;
            cur = cur->left;
        }
        return root;
    }

     TreeNode* convertBST(TreeNode* root, int& pre) {
        if (!root) {
            return NULL;
        }
        auto right = convertBST(root->right, pre);
        root->val += pre;
        pre = root->val;
        convertBST(root->left, pre);
        return root;
     }


    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        int pre = 0;
        return convertBST(root, pre);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [0,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4,1]\n
// @lcpr case=end

 */

