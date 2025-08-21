/*
 * @lc app=leetcode.cn id=1932 lang=cpp
 * @lcpr version=30204
 *
 * [1932] 合并多棵二叉搜索树
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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> roots;
        for (auto& r: trees) {
            roots[r->val] = r;
        }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1],[3,2,5],[5,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,3,8],[3,2,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,4],[3]]\n
// @lcpr case=end

 */

