/*
 * @lc app=leetcode.cn id=LCR 052 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 052] 递增顺序搜索树
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* head = nullptr;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (pre) {
                cur->left = nullptr;
                pre->right = cur;
            } else {
                head = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,2,4,null,8,1,null,null,null,7,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,7]\n
// @lcpr case=end

 */

