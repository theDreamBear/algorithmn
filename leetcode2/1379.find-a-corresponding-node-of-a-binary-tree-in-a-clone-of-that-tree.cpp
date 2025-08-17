/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 * @lcpr version=30204
 *
 * [1379] 找出克隆二叉树中的相同节点
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;

        auto dfs = [&](this auto&& dfs, TreeNode* p, TreeNode* q) {
            if (!p and !q) return false;
            if (p == target) {
                ans = q;
                return true;
            }
            return dfs(p->left, q->left) or dfs(p->right, q->right);
        };
        dfs(original, cloned);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,4,3,null,null,6,19]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [8,null,6,null,5,null,4,null,3,null,2,null,1]\n4\n
// @lcpr case=end

 */

