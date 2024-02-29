/*
 * @lc app=leetcode.cn id=LCR 151 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 151] 彩灯装饰记录 III
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
        ans.push_back({root->val});
        q.push(root);
        int d = 0;
        while (!q.empty()) {
            d++;
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    temp.push_back(node->left->val);
                    q.push(node->left);
                }
                if (node->right) {
                    temp.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            if (!temp.empty()) {
                if (d & 0x1) {
                    reverse(temp.begin(), temp.end());
                }
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

