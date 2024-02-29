/*
 * @lc app=leetcode.cn id=LCR 149 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 149] 彩灯装饰记录 I
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
    vector<int> decorateRecord(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                ans.push_back(node->left->val);
            }
            if (node->right) {
                q.push(node->right);
                ans.push_back(node->right->val);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,17,21,18,null,null,6]\n
// @lcpr case=end

 */

