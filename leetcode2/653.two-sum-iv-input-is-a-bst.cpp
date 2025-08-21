/*
 * @lc app=leetcode.cn id=653 lang=cpp
 * @lcpr version=30204
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        auto in = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            vals.emplace_back(node->val);
            dfs(node->right);
        };
        in(root);

        for (int i = 0, j = vals.size() - 1; i < j; ) {
            int sum = vals[i] + vals[j];
            if (sum == k) return true;
            if (sum < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n9\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n28\n
// @lcpr case=end

 */

