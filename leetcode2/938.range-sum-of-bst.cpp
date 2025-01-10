/*
 * @lc app=leetcode.cn id=938 lang=cpp
 * @lcpr version=30204
 *
 * [938] 二叉搜索树的范围和
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
    int rangeSumBST1(TreeNode* root, int low, int high) {
        // 迭代非递归中序遍历
        int ans = 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            if (cur->val >= low and cur->val <= high) {
                ans += cur->val;
            }
            st.pop();
            cur = cur->right;
        }
        return ans;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int x = root->val;
        int sum = x >= low and x <= high ? x: 0;
        if (x > low) {
            sum += rangeSumBST(root->left, low, high);
        }
        if (x < high) {
            sum += rangeSumBST(root->right, low, high);
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,15,3,7,null,18]\n7\n15\n
// @lcpr case=end

// @lcpr case=start
// [10,5,15,3,7,13,18,1,null,6]\n6\n10\n
// @lcpr case=end

 */

