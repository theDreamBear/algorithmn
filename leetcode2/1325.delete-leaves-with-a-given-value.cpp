/*
 * @lc app=leetcode.cn id=1325 lang=cpp
 * @lcpr version=30204
 *
 * [1325] 删除给定值的叶子节点
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
#include <map>
#include <set>
#include <string>
#include <string.h>
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (!root->left  and !root->right) {
            return root->val == target ? nullptr : root;
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,2,null,2,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,3,3,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,2,null,2]\n2\n
// @lcpr case=end

 */

