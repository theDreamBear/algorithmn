/*
 * @lc app=leetcode.cn id=988 lang=cpp
 * @lcpr version=30204
 *
 * [988] 从叶结点开始的最小字符串
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
    string smallestFromLeaf(TreeNode* root) {
        string ans(1, char('z' + 1));
        string t;

        auto cmp = [&]() {
            int i = t.size() - 1, j = ans.size() - 1;
            for (; i >= 0 and j >= 0; i--, j--) {
                if (t[i] < ans[j]) return true;
                if (t[i] > ans[j]) return false;
            }
            if (j >= 0) return true;
            return false;
        };

        auto pre = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;
            t.push_back(char(node->val + 'a'));
            if (!node->left and !node->right) {
                if (cmp()) {
                    ans = t;
                }
            }
            dfs(node->left);
            dfs(node->right);
            t.pop_back();
        };
        pre(root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3,4,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [25,1,3,1,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,null,1,0,null,0]\n
// @lcpr case=end

 */

