/*
 * @lc app=leetcode.cn id=面试题 04.06 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.06] 后继者
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor1(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;
        bool ok = false;
        auto dfs = [&](auto&& dfs, TreeNode* node) {
            if (!node or res){
                return;
            }
            dfs(dfs, node->left);
            if (ok) {
                if (!res) res = node;
                return;
            }
            if (node == p) {
                ok =  true;
            }
            dfs(dfs, node->right);
        };
        dfs(dfs, root);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n12/ \1   3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n65/ \3   6/ \2   4/   1\n
// @lcpr case=end

 */

