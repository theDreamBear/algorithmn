/*
 * @lc app=leetcode.cn id=LCR 174 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 174] 寻找二叉搜索树中的目标节点
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
    int findTargetNode(TreeNode* root, int cnt) {
        // 中序遍历
        TreeNode* cur = root;
        stack<TreeNode*> q;
        while (cur || !q.empty()) {
            while (cur) {
                q.push(cur);
                cur = cur->right;
            }
            cur = q.top();
            q.pop();
            if (--cnt == 0) {
                return cur->val;
            }
            cur = cur->left;
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7, 3, 9, 1, 5]\n27/ \3   9/ \1   5\n
// @lcpr case=end

// @lcpr case=start
// [10, 5, 15, 2, 7, null, 20, 1, null, 6, 8]\n410/ \5   15/ \    \2   7    20/   / \ 1   6   8\n
// @lcpr case=end

 */

