/*
 * @lc app=leetcode.cn id=LCR 150 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 150] 彩灯装饰记录 II
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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root->val});
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if (node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            if (!temp.empty()) {
                ans.push_back(temp);
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

