/*
 * @lc app=leetcode.cn id=508 lang=cpp
 * @lcpr version=30204
 *
 * [508] 出现次数最多的子树元素和
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> cnt;
        auto post = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return 0;
            int l = dfs(node->left);
            int r = dfs(node->right);
            cnt[node->val + l + r]++;
            return node->val + l + r;
        };
        post(root);
        int maxsz = 0;
        for (auto& [_, sz]: cnt) {
            maxsz = max(maxsz, sz);
        }
        for (auto& [v, sz]: cnt) {
            if (sz == maxsz) ans.push_back(v);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,-3]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,-5]\n
// @lcpr case=end

 */

