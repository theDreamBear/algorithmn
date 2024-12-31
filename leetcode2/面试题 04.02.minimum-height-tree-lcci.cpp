/*
 * @lc app=leetcode.cn id=面试题 04.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.02] 最小高度树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        ranges::sort(nums);
        auto make = [&](auto&& make, int low, int high)->TreeNode* {
            if (low > high) {
                return nullptr;
            }
            int mid = (low + high) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = make(make, low, mid - 1);
            root->right = make(make, mid + 1, high);
            return root;
        };
        return make(make, 0, nums.size() - 1);
    }
};
// @lc code=end



