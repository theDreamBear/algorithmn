/*
 * @lc app=leetcode.cn id=LCR 153 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 153] 二叉树中和为目标值的路径
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
//  前序遍历
    void pathTarget(TreeNode* root, vector<vector<int>>& ans, vector<int>& temp, int current, int target) {
        if (!root) {
            return;
        }
        temp.push_back(root->val);
        current += root->val;
        if (!root->left and !root->right) {
            if (current == target) {
                ans.push_back(temp);
            }
            goto pop;
        }
        if (root->left) {
            pathTarget(root->left, ans, temp, current, target);
        }
        if (root->right) {
            pathTarget(root->right, ans, temp, current, target);
        }
        pop:
            temp.pop_back();
       return;
    }

    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        pathTarget(root, ans, temp, 0, target);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */

