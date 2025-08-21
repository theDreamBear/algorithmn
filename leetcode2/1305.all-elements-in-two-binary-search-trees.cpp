/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 * @lcpr version=30204
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        auto gen = [](TreeNode* node) {
            stack<TreeNode*> st;
            while (node) {
                st.push(node);
                node = node->left;
            }
            return [st=move(st)]() mutable {
                if (!st.empty()) {
                    auto cur = st.top();
                    st.pop();
                    int ans  = cur->val;
                    cur = cur->right;
                    while (cur) {
                        st.push(cur);
                        cur = cur->left;
                    }
                    return ans;
                }
                return INT_MAX;
            };
        };
        vector<int> ans;
        auto g1 = gen(root1), g2 = gen(root2);
        for (int left = g1(), right = g2(); left != INT_MAX or right != INT_MAX; ) {
            if (left <= right) {
                ans.push_back(left);
                left = g1();
            } else {
                ans.push_back(right);
                right = g2();
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,4]\n[1,0,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,8]\n[8,1]\n
// @lcpr case=end

 */

