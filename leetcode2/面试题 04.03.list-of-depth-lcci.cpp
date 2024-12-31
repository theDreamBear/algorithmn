/*
 * @lc app=leetcode.cn id=面试题 04.03 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.03] 特定深度节点链表
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;
        vector<ListNode*> tail;
        auto dfs = [&](auto&& dfs, TreeNode* node, int depth) {
            if (!node) {
                return;
            }
            if (depth >= ans.size()) {
                ans.resize(depth + 1);
                tail.resize(depth + 1);
            }
            ListNode* ld = new ListNode(node->val);
            if (ans[depth] == nullptr) {
                ans[depth] = ld;
                tail[depth] = ld;
            } else {
                tail[depth]->next= ld;
                tail[depth] = ld;
            }
            dfs(dfs, node->left, depth + 1);
            dfs(dfs, node->right, depth + 1);
        };
        dfs(dfs, tree, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,null,7,8]1/  \ 2    3/ \    \ 4   5    7/8\n
// @lcpr case=end

 */

