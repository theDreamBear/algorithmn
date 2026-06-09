/*
 * @lc app=leetcode.cn id=2196 lang=cpp
 * @lcpr version=30204
 *
 * [2196] 根据描述创建二叉树
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> memo;
        unordered_map<int, int> isroot;
        //TreeNode* root = nullptr;
        for (auto& vec: descriptions) {
            int pi = vec[0], ci = vec[1], left = vec[2];
            isroot[ci] = 0;
            if (!isroot.count(pi)) isroot[pi] = 1;
            if (!memo[ci]) memo[ci] = new TreeNode(ci);
            if (!memo[pi]) memo[pi] = new TreeNode(pi);
            if (left) memo[pi]->left = memo[ci];
            else memo[pi]->right = memo[ci];
        }
        // 找root
        for (auto& [pi, e]: isroot) {
            if (e) {
                return memo[pi];
            }
        }
        return nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1],[2,3,0],[3,4,1]]\n
// @lcpr case=end

 */

