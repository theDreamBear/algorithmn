/*
 * @lc app=leetcode.cn id=LCR 050 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 050] 路径总和 III
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
class Solution1 {
public:
    int previsit(TreeNode* node, vector<int>& st, int target) {
        if (!node) {
            return 0;
        }
        long long sum = node->val;
        int ans = 0;
        if (sum == target) {
            ++ans;
        }
        for (int i = st.size() - 1; i >= 0; i--) {
            sum += st[i];
            if (sum == target) {
                ++ans;
            }
        }
        st.push_back(node->val);
        ans += previsit(node->left, st, target);
        ans += previsit(node->right, st, target);
        st.pop_back();
        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> st;
        return previsit(root, st,  targetSum);
    }
};

class Solution {
public:
    int previsit(TreeNode* node, unordered_map<long long, int>& pre, long long sum, int target) {
        if (!node) {
            return 0;
        }
        sum += node->val;
        int ans = pre[sum - target];
        pre[sum]++;
        ans += previsit(node->left, pre, sum, target);
        ans += previsit(node->right, pre, sum, target);
        pre[sum]--;
        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> pre;
        pre[0] = 1;
        return previsit(root, pre, 0ll, targetSum);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */

