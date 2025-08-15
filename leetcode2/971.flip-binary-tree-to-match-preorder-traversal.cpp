/*
 * @lc app=leetcode.cn id=971 lang=cpp
 * @lcpr version=30204
 *
 * [971] 翻转二叉树以匹配先序遍历
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;

        auto get = [&](this auto&& dfs, TreeNode* node, vector<int>& vals) {
            if (!node) return;
            
        }

        auto check = [&](TreeNode* node, int l, int r) {

        };
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n[2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

 */

